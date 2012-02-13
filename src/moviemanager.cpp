/***************************************************************************
 *   Copyright (C) 2012 by Sandeep Raju P <sandeep080@gmail.com>           *
 *   Copyright (C) 2012 by Sadan Sohan M <sadansohanm@gmail.com>           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "moviemanager.h"
//#include "moviemanagerview.h"

#include "imdb.h"

#include "settings.h"

#include <QtGui/QDropEvent>
#include <QtGui/QPainter>
#include <QtGui/QPrinter>

#include <KConfigDialog>
#include <KStatusBar>

#include <KAction>
#include <KActionCollection>
#include <KStandardAction>

#include <KLocale>

//Qt includes
#include <QtDebug>
#include <QGraphicsScene>
#include <QScrollArea>
#include <QWebView>
#include <KRatingWidget>


////for testing/////
///pnh includes

//Nepomuk Includes
#include <Nepomuk/ResourceManager>
#include <Nepomuk/Query/Term>
#include <Nepomuk/Query/Result>
#include <Nepomuk/Query/ResourceTypeTerm>
#include <Nepomuk/Query/ComparisonTerm>
#include <Nepomuk/Query/LiteralTerm>
#include <Nepomuk/Query/QueryServiceClient>
#include <Nepomuk/Vocabulary/PIMO>
#include <Nepomuk/Vocabulary/NCO>
#include <Nepomuk/Vocabulary/NFO>
#include <Nepomuk/Vocabulary/NMM>
#include <Nepomuk/Query/AndTerm>
#include <Nepomuk/Query/OrTerm>
#include <Nepomuk/Vocabulary/NIE>
#include <Nepomuk/Query/QueryParser>
#include <Nepomuk/Variant>
#include <Nepomuk/Tag>
#include <Nepomuk/Utils/FacetWidget>
#include <Nepomuk/File>

//Soprano includes
#include <Soprano/QueryResultIterator>
#include <Soprano/Model>
#include <Soprano/Vocabulary/NAO>


///////////////


///// for playing video /////

#include <QDesktopServices>
#include <QUrl>

/////////////////////////////



////////////////////

MovieManager::MovieManager()
    : KXmlGuiWindow(),
      //m_view(new MovieManagerView(this)),
      m_printer(0)
{

    // accept dnd
    setAcceptDrops(true);

    // tell the KXmlGuiWindow that this is indeed the main widget
    //setCentralWidget(m_view);

    // then, setup our actions
    setupActions();

    // add a status bar
    statusBar()->show();


    //MovieManager UI is setup here
    setupUserInterface();
    ///////////////////////////////

    getNepomukData();






    //slotPlayVideo(QUrl("file:///home/sandeep/Videos/Gracie.avi"));

    // a call to KXmlGuiWindow::setupGUI() populates the GUI
    // with actions, using KXMLGUI.
    // It also applies the saved mainwindow sKApplication appettings, if any, and ask the
    // mainwindow to automatically save settings if changed: window size,
    // toolbar position, icon size, etc.
    setupGUI();

    this->setGeometry(350,50,800,600);
    this->setMinimumSize(800,600);
    this->setMaximumSize(800,600);
}

MovieManager::~MovieManager()
{
}

void MovieManager::setupActions()
{
    //KStandardAction::openNew(this, SLOT(fileNew()), actionCollection());

    //This quits the application
    KStandardAction::quit(this, SLOT(slotQuitApplication()), actionCollection());
    //This is used to invoke the preference window in the application (a new QDialog box)
    KStandardAction::preferences(this, SLOT(optionsPreferences()), actionCollection());

    // custom menu and menu item - the slot is in the class MovieManagerView
    //KAction *custom = new KAction(KIcon("colorize"), i18n("Swi&tch Colors"), this);
    //actionCollection()->addAction( QLatin1String("switch_action"), custom );
    //connect(custom, SIGNAL(triggered(bool)), m_view, SLOT(switchColors()));
}

void MovieManager::fileNew()
{
    // this slot is called whenever the File->New menu is selected,
    // the New shortcut is pressed (usually CTRL+N) or the New toolbar
    // button is clicked

    // create a new window
    //(new MovieManager)->show();
}

void MovieManager::optionsPreferences()
{
    /*
    // The preference dialog is derived from prefs_base.ui
    //
    // compare the names of the widgets in the .ui file
    // to the names of the variables in the .kcfg file
    //avoid to have 2 dialogs shown
    if ( KConfigDialog::showDialog( "settings" ) )  {
        return;
    }
    KConfigDialog *dialog = new KConfigDialog(this, "settings", Settings::self());
    QWidget *generalSettingsDlg = new QWidget;
    ui_prefs_base.setupUi(generalSettingsDlg);
    dialog->addPage(generalSettingsDlg, i18n("General"), "package_setting");
    connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChanged()));
    dialog->setAttribute( Qt::WA_DeleteOnClose );
    dialog->show();
*/
}

void MovieManager::slotQuitApplication()
{
    //This is not the right procedure to quit a KDE application
    //The correct way -> use KStandardAction to a predefined quit function!
    qDebug("quitting!");
    Qt:exit(0); //this is generating some warning
}

void MovieManager::setupUserInterface()
{
    //This function is used to build the user interface of the complete application...
    mainWindow = new QWidget(this);

    //add Vbox to mainWindow
    vMainLayout = new QVBoxLayout(mainWindow);
    hTopLayout = new QHBoxLayout(mainWindow);

    mainWindow->setLayout(vMainLayout);


    //preparing widgets to add to layout
    searchLabel = new QLabel("Search:  ",mainWindow);
    searchBar = new KLineEdit("",mainWindow);
    //searchButton = new KPushButton("SEARCH",mainWindow);

    //creating a connection for the searchbar
    //to trigger a function as soon as the user enters something
    connect(searchBar,SIGNAL(textChanged(QString)),this,SLOT(slotSearchBarTextChanged(QString)));


    //adding htoplayout to vmainlayout
    vMainLayout->addItem(hTopLayout);
    hTopLayout->addWidget(searchLabel);
    hTopLayout->addWidget(searchBar);

    //creating new hbottomlayout
    hBottomLayout = new QHBoxLayout(mainWindow);


    QVBoxLayout * vLayout;// = new QVBoxLayout(mainWindow);

    vLayout = vMainLayout;

    QScrollArea * scrollArea = new QScrollArea(mainWindow);
    vLayout->addWidget(scrollArea);

    //set up parameters for scroll area
    scrollArea->setWidgetResizable(false);


    //create another widget with a QVBoxLayout
    QVBoxLayout * scrollAreaVLayout = new QVBoxLayout(mainWindow);  //
    QWidget * scrollAreaWidgetContents = new QWidget(mainWindow);  //
    scrollAreaWidgetContents->setLayout(scrollAreaVLayout);
    scrollAreaVLayout->setSizeConstraint(QLayout::SetFixedSize);

    //add scrolling widget to scroller
    scrollArea->setWidget(scrollAreaWidgetContents);
    //this->setCentralWidget(mainWidget);


    //these are the widgets that need to be added to the scrollAreaLayout
    /*
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));

    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));

    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));

    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));

    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));

    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));

    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));

    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    scrollAreaVLayout->addWidget(new KLineEdit("", scrollAreaWidgetContents));
    */

    /*
    //------------- list item generator --------------------------------------
    //creating the poster (artwork) of the movie using QWebView

    QWebView* poster = new QWebView(scrollAreaWidgetContents);
    poster->load(QUrl("file:///home/sandeep/.moviemanager/avatar2.jpg"));
    poster->setMinimumSize(320, 474);   //ensuring that the rendering size is const.
    poster->setMaximumSize(320, 474);   //ensuring that the rendering size is const.


    //This is the layout that is to be added to the scrollAreaLayout
    //tempHLayout acts as a ListItem in the moviemanager

    QHBoxLayout* tempHLayout = new QHBoxLayout(scrollAreaWidgetContents);

    //adding the poster to the tempHLayout --> adding the poster to the ListItem
    tempHLayout->addWidget(poster);


    //This is the Vlayout inside our listitem which is added after the poster
    //This contains other HLayouts which inturn contain the metadata of the movie
    QVBoxLayout* insideVLayout = new QVBoxLayout(scrollAreaWidgetContents);

    //this is the layout that contains the metadata. and acts as an item inside a list item. (!important)
    QHBoxLayout* nameHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    nameHLayout->addWidget(new QLabel("Title: ", scrollAreaWidgetContents));
    nameHLayout->addWidget(new QLabel("Avatar", scrollAreaWidgetContents));


    QHBoxLayout* directorHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    directorHLayout->addWidget(new QLabel("Director: ", scrollAreaWidgetContents));
    directorHLayout->addWidget(new QLabel("James Cameron", scrollAreaWidgetContents));


    //adding the rating widget
    QHBoxLayout* ratingHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    ratingHLayout->addWidget(new QLabel("Rating: ", scrollAreaWidgetContents));
    ratingHLayout->addWidget(new KRatingWidget(scrollAreaWidgetContents));

    insideVLayout->addItem(nameHLayout);
    insideVLayout->addItem(directorHLayout);
    insideVLayout->addItem(ratingHLayout);

    //finally adding the metadata layout to the ListItem
    tempHLayout->addItem(insideVLayout);


    //------------- list item generator ends--------------------------------
    //-------------- tempHLayout should be returned ------------------------
    */

    //adding the ListItem into the Main List!!
    scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents));   //instead of passing this, make this the class datamember
    scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents));


    hBottomLayout->addItem(vLayout);

    setCentralWidget(mainWindow);



}

//user defined slots here...

void MovieManager::slotSearchBarTextChanged(QString userInput)
{
    //qDebug("user is typing this >> ");
    qDebug(userInput.toAscii());    //this is generating some warning

    //query nepomuk or from the results already generated and display appropriate things in the list!



}


void MovieManager::getNepomukData()
{
    Nepomuk::Resource *test = new Nepomuk::Resource("/home/sandeep/Videos/Gracie.avi");
    test->addType(Nepomuk::Vocabulary::NMM::Movie());
    test->setRating(4);


    Nepomuk::Query::Term term =  Nepomuk::Query::ResourceTypeTerm( Nepomuk::Vocabulary::NFO::Video()) ||
                Nepomuk::Query::ComparisonTerm(Nepomuk::Vocabulary::NIE::mimeType(),
                                               Nepomuk::Query::LiteralTerm(QLatin1String("video")) );

    Nepomuk::Query::Query m_currentQuery;
    m_currentQuery.setTerm(term);
    m_currentQuery.setLimit( 30 );
    qDebug()<<m_currentQuery.toSparqlQuery();
    QList<Nepomuk::Query::Result> results = Nepomuk::Query::QueryServiceClient::syncQuery( m_currentQuery );
    //QList<Nepomuk::Resource> resources;
    Q_FOREACH( const Nepomuk::Query::Result& result,results) {
        //addIconToResource(result.resource());
        qDebug()<<result.resource().genericLabel();


        QString temp(result.resource().genericLabel().remove(result.resource().genericLabel().length()-4,4));

        qDebug(temp.toLatin1().data());

        //s.remove(1, 4);
        if(temp.contains("KDE") != true)
        {
            IMDB* imdb = new IMDB(temp.toLatin1().data());
            imdb->getData();
            qDebug("finished fetching");
        }

        //resources.append( result.resource() );
    }
    //resourceSort(resources);
    //m_resourceViewModel->setResources( resources );


}

void MovieManager::slotPlayVideo(QUrl videoUrl)
{
    QDesktopServices::openUrl(videoUrl);
}

QHBoxLayout* MovieManager::createMovieManagerlistItem(QWidget* scrollAreaWidgetContents/*, QString mTitle, QString mYear, QString mRated, QString mReleased, QString mGenre, QString mDirector, QString mWriter, QString mActors, QString mPlot, QUrl mPoster, QString mRuntime, QString mIMDBRating, QString mVotes, QString mID, QString mResponse*/)
{
    //important - next todo

    //This function generates the pseudo list item in the movie manager
    //based on the metadata passed as the parameters to this function
    //it returns a pointer to QHBoxLayout

    //QHBoxLayout* hItem = new QHBoxLayout(mainWindow);
    /*QLabel* image = new QLabel("", mainWindow);
    image->setPixmap(QPixmap("/home/sandeep/.moviemanager/avatar.jpg"));
    QLabel* mName = new QLabel("avatar", mainWindow);
    KPushButton* mPlay = new KPushButton("PLAY", mainWindow);

    hItem->addWidget(image);
    hItem->addWidget(mName);
    hItem->addWidget(mPlay);
    */
    //return hItem;


    //------------- list item generator --------------------------------------
    //creating the poster (artwork) of the movie using QWebView

    QWebView* poster = new QWebView(scrollAreaWidgetContents);
    poster->load(QUrl("file:///home/sandeep/.moviemanager/avatar2.jpg"));
    //poster->setMinimumSize(320, 474);   //ensuring that the rendering size is const.
    //poster->setMaximumSize(320, 474);   //ensuring that the rendering size is const.
    poster->setMinimumSize(200,290);
    poster->setMaximumSize(200,290);

    //This is the layout that is to be added to the scrollAreaLayout
    //tempHLayout acts as a ListItem in the moviemanager

    QHBoxLayout* tempHLayout = new QHBoxLayout(scrollAreaWidgetContents);

    //adding the poster to the tempHLayout --> adding the poster to the ListItem
    tempHLayout->addWidget(poster);


    //This is the Vlayout inside our listitem which is added after the poster
    //This contains other HLayouts which inturn contain the metadata of the movie
    QVBoxLayout* insideVLayout = new QVBoxLayout(scrollAreaWidgetContents);

    //this is the layout that contains the metadata. and acts as an item inside a list item. (!important)
    QHBoxLayout* nameHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    nameHLayout->addWidget(new QLabel("Title: ", scrollAreaWidgetContents));
    nameHLayout->addWidget(new QLabel("Avatar", scrollAreaWidgetContents));


    QHBoxLayout* directorHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    directorHLayout->addWidget(new QLabel("Director: ", scrollAreaWidgetContents));
    directorHLayout->addWidget(new QLabel("James Cameron", scrollAreaWidgetContents));


    //adding the rating widget
    QHBoxLayout* ratingHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    ratingHLayout->addWidget(new QLabel("Rating: ", scrollAreaWidgetContents));
    ratingHLayout->addWidget(new KRatingWidget(scrollAreaWidgetContents));

    insideVLayout->addItem(nameHLayout);
    insideVLayout->addItem(directorHLayout);
    insideVLayout->addItem(ratingHLayout);

    //finally adding the metadata layout to the ListItem
    tempHLayout->addItem(insideVLayout);


    //------------- list item generator ends--------------------------------
    //-------------- tempHLayout should be returned ------------------------

    return tempHLayout;


}

void MovieManager::populateResources()
{

}

#include "moviemanager.moc"
