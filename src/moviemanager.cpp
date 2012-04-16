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

#include <QListView>

//Qt includes
#include <QMessageBox>
#include <QListView>
#include <QDockWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QButtonGroup>
#include <QToolButton>
#include <QMenu>
#include <QLabel>
#include <QSize>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QHash>

#include "nmm/movie.h"
#include "nfo/video.h"

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

//Nepomuk includes
#include <Nepomuk/Utils/SimpleResourceModel>
#include <Nepomuk/Query/Term>
#include <Nepomuk/Query/Query>

#include <QToolButton>
#include <QComboBox>

///// for playing video /////
#include <QDesktopServices>
#include <QUrl>
#include <QHash>


//RAKESH QLISTWIDGET////
#include <QListWidget>
#include <QListWidgetItem>
////////////////////////

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

    //getNepomukData();
    //MovieManager UI is setup here
    //setupUserInterface();
    ///////////////////////////////

    //RAKESH START/////////////
    setupRakeshUI();
    //RAKESH END///////////////

    //setupNewUserInterface();
    //setupNewModels();
    //populateDefaultResources();

    // a call to KXmlGuiWindow::setupGUI() populates the GUI
    // with actions, using KXMLGUI.
    // It also applies the saved mainwindow sKApplication appettings, if any, and ask the
    // mainwindow to automatically save settings if changed: window size,
    // toolbar position, icon size, etc.
    setupGUI();

    this->setGeometry(350,50,800,600);
    this->setMinimumSize(800,600);
    this->setMaximumSize(800,600);
    //this->setMaximumSize(800,600);
}

MovieManager::~MovieManager()
{
}

void MovieManager::openThat(QModelIndex i)
{
    qDebug() << "theri";
    //qDebug() << witem->text();
}

void MovieManager::setupRakeshUI()
{
    mainWindow = new QWidget(this);
    vMainLayout = new QVBoxLayout(mainWindow);
    hTopLayout = new QHBoxLayout(mainWindow);

    mainWindow->setLayout(vMainLayout);

    searchLabel = new QLabel("Search:  ",mainWindow);
    searchBar = new KLineEdit("",mainWindow);

    connect(searchBar,SIGNAL(returnPressed(QString)),this,SLOT(slotSearchBarTextChanged(QString)));

    vMainLayout->addItem(hTopLayout);
    hTopLayout->addWidget(searchLabel);
    hTopLayout->addWidget(searchBar);

    listWidget = new QListWidget(mainWindow);
    listWidget->setSortingEnabled(true);

    Nepomuk::Query::Term term =  Nepomuk::Query::ResourceTypeTerm( Nepomuk::Vocabulary::NFO::Video());
    Nepomuk::Query::Query m_currentQuery;
    m_currentQuery.setTerm(term);
    QList<Nepomuk::Query::Result> results = Nepomuk::Query::QueryServiceClient::syncQuery( m_currentQuery );
    //globalResults = results;


    Q_FOREACH( const Nepomuk::Query::Result& result,results) {
        listWidget->addItem(new QListWidgetItem(result.resource().property(Nepomuk::Vocabulary::NFO::fileName()).toString()));
    }

    connect(listWidget,SIGNAL(doubleClicked(QModelIndex)),this, SLOT(openThat(QModelIndex)));

//    listWidget->addItem(new QListWidgetItem("Oak"));
//    listWidget->addItem(new QListWidgetItem("Banana"));
//    listWidget->addItem(new QListWidgetItem("Apple"));
//    listWidget->addItem(new QListWidgetItem("Orange"));
//    listWidget->addItem(new QListWidgetItem("Grapes"));
//    listWidget->addItem(new QListWidgetItem("Jayesh"));
//    listWidget->addItem(new QListWidgetItem("Pineapple"));
//    listWidget->addItem(new QListWidgetItem("GROUNDNUT"));
//    listWidget->addItem(new QListWidgetItem("Sugarcane"));
//    listWidget->addItem(new QListWidgetItem("Coconut"));
//    listWidget->addItem(new QListWidgetItem("Remote"));
//    listWidget->addItem(new QListWidgetItem("Mango"));

    //connect(listWidget->indexWidget(QModelIndex()))

     vMainLayout->addWidget(listWidget);

     setCentralWidget(mainWindow);


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

    // The preference dialog is derived from prefs_base.ui
    //
    // compare the names of the widgets in the .ui file
    // to the names of the variables in the .kcfg file
    //avoid to have 2 dialogs shown
//    if ( KConfigDialog::showDialog( "settings" ) )  {
//        return;
//    }
//    KConfigDialog *dialog = new KConfigDialog(this, "settings", Settings::self());
//    QWidget *generalSettingsDlg = new QWidget;
//    ui_prefs_base.setupUi(generalSettingsDlg);
//    dialog->addPage(generalSettingsDlg, i18n("General"), "package_setting");
//    connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChanged()));
//    dialog->setAttribute( Qt::WA_DeleteOnClose );
//    dialog->show();

}

void MovieManager::slotQuitApplication()
{
    //This is not the right procedure to quit a KDE application
    //The correct way -> use KStandardAction to a predefined quit function!
    qDebug("quitting!");
    Qt:exit(0); //this is generating some warning
}

//NEW APPLICATION GOES HERE
void MovieManager::setupNewUserInterface()
{
    mainWindow = new QWidget(this);
    vMainLayout = new QVBoxLayout(mainWindow);
    hTopLayout = new QHBoxLayout(mainWindow);

    mainWindow->setLayout(vMainLayout);

    searchLabel = new QLabel("Search:  ",mainWindow);
    searchBar = new KLineEdit("",mainWindow);

    connect(searchBar,SIGNAL(returnPressed(QString)),this,SLOT(slotSearchBarTextChanged(QString)));

    vMainLayout->addItem(hTopLayout);
    hTopLayout->addWidget(searchLabel);
    hTopLayout->addWidget(searchBar);

    //setting up the result panel
    resultPanel = new QListView(mainWindow);
    resultPanel->setContextMenuPolicy(Qt::CustomContextMenu);
    resultPanel->setViewMode(resultPanel->ListMode);
    resultPanel->setSpacing(50);
    //QStyle* tempStyle = new QStyle();
    //resultPanel->setStyle();
    //resultPanel->setBaseSize(100,100);
    resultPanel->setIconSize(QSize(42,42));
    resultPanel->setUniformItemSizes(true);

    //connecting the result panel item doubleclick to a slot
    connect(resultPanel,SIGNAL(clicked(QModelIndex)),this,SLOT(slotOpenResource(QModelIndex)));

    vMainLayout->addWidget(resultPanel);

    //query nepomuk and check if the IMDB_ID has been set. If so, then add the resource
    //to the list else check if it is NA
    //if it is NA ignore
    //else call the imdb function to populate the resources
    //after populating the resource, add to this result list.



    setCentralWidget(mainWindow);

}

void MovieManager::populateDefaultResources()
{
    m_resourceViewModel->clear();

    Nepomuk::Query::Term term =  Nepomuk::Query::ResourceTypeTerm( Nepomuk::Vocabulary::NFO::Video());
    Nepomuk::Query::Query m_currentQuery;
    m_currentQuery.setTerm(term);
    QList<Nepomuk::Query::Result> results = Nepomuk::Query::QueryServiceClient::syncQuery( m_currentQuery );
    QList<Nepomuk::Resource> resources;

    Q_FOREACH( const Nepomuk::Query::Result& result,results) {
        addIconToResource(result.resource());
        qDebug()<<result.resource().property(Nepomuk::Vocabulary::NFO::fileName()).toString();
        resources.append( result.resource() );
    }
    resourceSort(resources);

    m_resourceViewModel->setResources( resources );


}

void MovieManager::resourceSort(QList<Nepomuk::Resource> &resources)
{
    for (int i=0; i<resources.size()-1; i++) {
        for (int j=0; j<resources.size()-1; j++) {
            if (resources.at(j).usageCount() < resources.at(j+1).usageCount()) {
                Nepomuk::Resource temp = resources.at(j);
                resources.replace(j,resources.at(j+1));
                resources.replace(j+1,temp);
            }
        }
    }
}

void MovieManager::addIconToResource(Nepomuk::Resource rsc)
{
    rsc.addSymbol("folder-blue");

    /*if(rsc.className().compare("Folder") == 0) {
        rsc.addSymbol("folder-blue");
    }
    else if(rsc.className().compare("RasterImage") == 0) {
        rsc.addSymbol("image-x-generic");
    }
    else if(rsc.className().compare("Document") == 0) {
        rsc.addSymbol("libreoffice34-oasis-master-document");
    }
    else if(rsc.className().compare("Audio") == 0) {
        rsc.addSymbol("audio-basic");
    }
    else if(rsc.className().compare("InformationElement") == 0) {
        rsc.addSymbol("video-x-generic");
    }
    else if(rsc.className().compare("TextDocument") == 0) {
        rsc.addSymbol("text-x-generic");
    }
    else if(rsc.className().compare("PaginatedTextDocument") == 0) {
        rsc.addSymbol("application-pdf");
    }
    else if(rsc.className().compare("Archive") == 0) {
        rsc.addSymbol("application-x-archive");
    }
    else if(rsc.className().compare("Person") == 0){
        rsc.addSymbol("user-identity");
    }
    else if(rsc.className().compare("Website") == 0) {
        rsc.addSymbol("text-html");
    }*/

}

void MovieManager::setupNewModels()
{
    m_resourceViewModel = new Nepomuk::Utils::SimpleResourceModel(this);
    resultPanel->setModel(m_resourceViewModel);
    connect(resultPanel->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(slotResultPanelSelectionChanged()));
    //connect(resultPanel->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(slotRecommendedResources()));


}

void MovieManager::slotResultPanelSelectionChanged()
{
    qDebug() << "selection changed";
}

void MovieManager::slotOpenResource(QModelIndex)
{
    qDebug() << "helloWorld";

    //this will be triggered when we double click on the movie item.
    //here new dialog box needs to be opened...
    //then we need to query nnepomuk only for that movie name and show them.
}

//NEW APPLICATION ENDS HERE

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
    connect(searchBar,SIGNAL(returnPressed(QString)),this,SLOT(slotSearchBarTextChanged(QString)));


    //adding htoplayout to vmainlayout
    vMainLayout->addItem(hTopLayout);
    hTopLayout->addWidget(searchLabel);
    hTopLayout->addWidget(searchBar);

    //creating new hbott/home/sandeep/Videos/Gracie.aviomlayout
    hBottomLayout = new QHBoxLayout(mainWindow);


    QVBoxLayout * vLayout;// = new QVBoxLayout(mainWindow);

    vLayout = vMainLayout;

    QScrollArea * scrollArea = new QScrollArea(mainWindow);
    vLayout->addWidget(scrollArea);

    //set up parameters for scroll area
    scrollArea->setWidgetResizable(false);


    //create another widget with a QVBoxLayout
    scrollAreaVLayout = new QVBoxLayout(mainWindow);  //
    scrollAreaWidgetContents = new QWidget(mainWindow);  //
    scrollAreaWidgetContents->setLayout(scrollAreaVLayout);
    scrollAreaVLayout->setSizeConstraint(QLayout::SetFixedSize);

    //add scrolling widget to scroller
    scrollArea->setWidget(scrollAreaWidgetContents);
    //this->setCentralWidget(mainWidget);

    //////////ALL THESE BELOW SHOULD BE SET BY FETCHING DATA FROM NEPOMUK//////////////////
    /////PUT A FOR LOOP AND DO ALL THE THINGS...

    Nepomuk::Query::Term term =  Nepomuk::Query::ResourceTypeTerm( Nepomuk::Vocabulary::NFO::Video());
    Nepomuk::Query::Query m_currentQuery;
    m_currentQuery.setTerm(term);
    QList<Nepomuk::Query::Result> results = Nepomuk::Query::QueryServiceClient::syncQuery( m_currentQuery );
    globalResults = results;


    Q_FOREACH( const Nepomuk::Query::Result& result,results) {

        //vHanda
        QHash<QString, Nepomuk::Variant> props =  result.resource().allProperties();
        //result.resource().allResources()

        qDebug() << "------------------------vHanda START---------*********";
        //QList<Nepomuk::Variant> pList = props.values();


        QList<QString> keys =  props.keys();

        Q_FOREACH( QString key, keys)
        {
            qDebug() << key;
        }

        qDebug() << "-------------------vHanda END--------------*********";



        if(result.resource().genericLabel().contains(".avi") == true && result.resource().property(Nepomuk::Vocabulary::NMM::synopsis()).toString().contains("tt") == true) {

            resultListRef += createMovieManagerlistItem(scrollAreaWidgetContents,
                                                            QString(result.resource().property(Nepomuk::Vocabulary::NFO::fileName()).toString().toLatin1().data()),QString("08-05-1991"),
                                                            result.resource().rating(),QString("Comedy"),
                                                            QString("Rakesh"),QString("Swamy"),
                                                            QString("sumanth"),QString("The specification for the next stage is the output of the each design activity. This specification may be an abstract, formal specification that is produced to clarify the requirements or it may be a specification of how part of the system is to be realized."),
                                                            QUrl("file:///home/sandeep/.moviemanager/"+result.resource().property(Nepomuk::Vocabulary::NMM::synopsis()).toString()+".jpg"),QString("2:30 mins"),
                                                            QString("3"));
            scrollAreaVLayout->addItem(resultListRef.back());
        }

    }

       hBottomLayout->addItem(vLayout);

    setCentralWidget(mainWindow);



}

//user defined slots here...

void MovieManager::slotSearchBarTextChanged(QString userInput)
{
    //qDebug("user is typing this >> ");
    qDebug(userInput.toLatin1().data());    //this is generating some warning
    //int count = listWidget->count();

    //delete all the items in the results
    while(listWidget->count() != 0)
    {
        qDebug() << listWidget->itemAt(0,0)->text();
        delete listWidget->itemAt(0,0);
    }

    //qDebug() << "outside for:::::" << listWidget->item(2)->text();

    Nepomuk::Query::Term term =  Nepomuk::Query::ResourceTypeTerm( Nepomuk::Vocabulary::NFO::Video());
    Nepomuk::Query::Query m_currentQuery;
    m_currentQuery.setTerm(term);
    QList<Nepomuk::Query::Result> results = Nepomuk::Query::QueryServiceClient::syncQuery( m_currentQuery );
    //globalResults = results;


    Q_FOREACH( const Nepomuk::Query::Result& result,results) {
        if(result.resource().property(Nepomuk::Vocabulary::NFO::fileName()).toString().contains(userInput))
        listWidget->addItem(new QListWidgetItem(result.resource().property(Nepomuk::Vocabulary::NFO::fileName()).toString()));
    }




}


void MovieManager::getNepomukData()
{
    //----------------------FUNCTIONALITY------------------------------------------
    //fetch all the files to a Nepomuk resource list
    //iterate through the resource list
    //  if(resource is newly indexed && file_extension == .avi or .flv)
    //      then fetch data from imdb and populate the fields
    //
    //now fetch the files again into the Nepomuk resource list
    //iterate through the resource list
    //  if(file_extension == .avi or .flv)
    //      create a new our_list_item
    //      and populate to the list
    //-----------------------------------------------------------------------------


    //-----------------------CODE--------------------------------------------------

    //constructing a query
    Nepomuk::Query::Term term =  Nepomuk::Query::ResourceTypeTerm( Nepomuk::Vocabulary::NFO::Video());

    Nepomuk::Query::Query m_currentQuery;
    m_currentQuery.setTerm(term);
    //m_currentQuery.setLimit( 30 );
    //executing the query
    QList<Nepomuk::Query::Result> results = Nepomuk::Query::QueryServiceClient::syncQuery( m_currentQuery );

    //first iteration
    Q_FOREACH( const Nepomuk::Query::Result& result,results) {
        //**FOR LOOP STARTS HERE
        //QString temp(result.resource().genericLabel().remove(result.resource().genericLabel().length()-4,4));
        //qDebug(temp.toLatin1().data());


        //Nepomuk::operator <<()
        //Nepomuk::Vocabulary::NCO* actor1 = new Nepomuk::Vocabulary::NCO();
        //resource().setProperty(Nepomuk::Vocabulary::NMM::actor(),);

        qDebug()<<"Actor------>"<<result.resource().property(Nepomuk::Vocabulary::NMM::actor());

        qDebug() << result.resource().property(Nepomuk::Vocabulary::NFO::fileName()).toString().remove(".avi");

        //check if the filename contains ".avi" to filter all the results
        //this is not the correct implementation
        //but ok for current testing

        if(result.resource().genericLabel().contains(".avi") == true && result.resource().property(Nepomuk::Vocabulary::NMM::synopsis()).toString().contains("tt") == false) {
            qDebug() << "FETCHING RESOURCES FOR: " << result.resource().property(Nepomuk::Vocabulary::NFO::fileName()).toString();

            IMDB* imdb = new IMDB(result.resource().property(Nepomuk::Vocabulary::NFO::fileName()).toString().remove(".avi"), result.resource());
            //temporarily disabled (for faster startup)
            imdb->getData();

            Nepomuk::Resource* tempImage = new Nepomuk::Resource("/home/sandeep/.moviemanager/lagaan.jpg");
            tempImage->addType(Nepomuk::Vocabulary::NFO::Image());
            //tempActor.set

            result.resource().setProperty(Nepomuk::Vocabulary::NMM::artwork(),*tempImage);



            qDebug() << "POSTER URL>>>>>>>> " << result.resource().property(Nepomuk::Vocabulary::NMM::artwork()).toString();


            //result.resource().setRating(4);




        }


    }





}

void MovieManager::slotPlayVideo(QUrl videoUrl)
{
    QDesktopServices::openUrl(videoUrl);
}

QHBoxLayout* MovieManager::createMovieManagerlistItem(QWidget* scrollAreaWidgetContents,
                                                      QString mTitle, QString mReleased,
                                                      quint32 mRated, QString mGenre,
                                                      QString mDirector, QString mWriter,
                                                      QString mActors, QString mPlot,
                                                      QUrl mPoster, QString mRuntime,
                                                      QString mIMDBRating)
{



    QWebView* poster = new QWebView(scrollAreaWidgetContents);
    poster->load(mPoster);
    //poster->load(QUrl("file:///home/sandeep/.moviemanager/avatar2.jpg"));
    poster->setMinimumSize(200,290);
    poster->setMaximumSize(200,290);

    QHBoxLayout* tempHLayout = new QHBoxLayout(scrollAreaWidgetContents);

    tempHLayout->addWidget(poster);

    QVBoxLayout* insideVLayout = new QVBoxLayout(scrollAreaWidgetContents);

    //mainHLayout->addWidget(new QLineEdit("",helloWidget));
    tempHLayout->addItem(insideVLayout);


    //-------------Title-------------------------------------
    QHBoxLayout* titleHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    QLabel* titleLabel = new QLabel("Title: ", scrollAreaWidgetContents);

    titleLabel->setMinimumWidth(120);
    titleLabel->setAlignment(Qt::AlignTop);
    titleLabel->setAlignment(Qt::AlignLeft);

    titleHLayout->addWidget(titleLabel);
    QLabel* titleContent = new QLabel(mTitle,scrollAreaWidgetContents);

    titleContent->setMinimumWidth(150);
    //titleContent->setMinimumHeight(300);
    titleContent->setWordWrap(true);
    titleContent->setAlignment(Qt::AlignJustify);
    titleContent->setAlignment(Qt::AlignTop);
    titleContent->setAlignment(Qt::AlignLeft);

    titleHLayout->addWidget(titleContent);

    insideVLayout->addItem(titleHLayout);
    //------------end of title------------------------------

    //-------------actor-------------------------------------
        QHBoxLayout* actorHLayout = new QHBoxLayout(scrollAreaWidgetContents);
        QLabel* actorLabel = new QLabel("Actor: ", scrollAreaWidgetContents);

        actorLabel->setMinimumWidth(120);
        actorLabel->setAlignment(Qt::AlignTop);
        actorLabel->setAlignment(Qt::AlignLeft);

        actorHLayout->addWidget(actorLabel);
        QLabel* actorContent = new QLabel(mActors,scrollAreaWidgetContents);

        actorContent->setMinimumWidth(150);
        //actorContent->setMinimumHeight(300);
        actorContent->setWordWrap(true);
        actorContent->setAlignment(Qt::AlignJustify);
        actorContent->setAlignment(Qt::AlignTop);
        actorContent->setAlignment(Qt::AlignLeft);

        actorHLayout->addWidget(actorContent);

        insideVLayout->addItem(actorHLayout);
        //------------end of actor------------------------------

        //-------------director-------------------------------------
            QHBoxLayout* directorHLayout = new QHBoxLayout(scrollAreaWidgetContents);
            QLabel* directorLabel = new QLabel("Director: ", scrollAreaWidgetContents);

            directorLabel->setMinimumWidth(120);
            directorLabel->setAlignment(Qt::AlignTop);
            directorLabel->setAlignment(Qt::AlignLeft);

            directorHLayout->addWidget(directorLabel);
            QLabel* directorContent = new QLabel(mDirector,scrollAreaWidgetContents);

            directorContent->setMinimumWidth(150);
            //directorContent->setMinimumHeight(300);
            directorContent->setWordWrap(true);
            directorContent->setAlignment(Qt::AlignJustify);
            directorContent->setAlignment(Qt::AlignTop);
            directorContent->setAlignment(Qt::AlignLeft);

            directorHLayout->addWidget(directorContent);

            insideVLayout->addItem(directorHLayout);
            //------------end of director------------------------------

            //-------------writer-------------------------------------
                QHBoxLayout* writerHLayout = new QHBoxLayout(scrollAreaWidgetContents);
                QLabel* writerLabel = new QLabel("Writer: ", scrollAreaWidgetContents);

                writerLabel->setMinimumWidth(120);
                writerLabel->setAlignment(Qt::AlignTop);
                writerLabel->setAlignment(Qt::AlignLeft);

                writerHLayout->addWidget(writerLabel);
                QLabel* writerContent = new QLabel(mWriter,scrollAreaWidgetContents);

                writerContent->setMinimumWidth(150);
                //writerContent->setMinimumHeight(300);
                writerContent->setWordWrap(true);
                writerContent->setAlignment(Qt::AlignJustify);
                writerContent->setAlignment(Qt::AlignTop);
                writerContent->setAlignment(Qt::AlignLeft);

                writerHLayout->addWidget(writerContent);

                insideVLayout->addItem(writerHLayout);
                //------------end of writer------------------------------

                //-------------plot-------------------------------------
                    QHBoxLayout* plotHLayout = new QHBoxLayout(scrollAreaWidgetContents);
                    QLabel* plotLabel = new QLabel("Plot: ", scrollAreaWidgetContents);

                    plotLabel->setMinimumWidth(120);
                    plotLabel->setAlignment(Qt::AlignTop);
                    plotLabel->setAlignment(Qt::AlignLeft);

                    plotHLayout->addWidget(plotLabel);
                    QLabel* plotContent = new QLabel(mPlot,scrollAreaWidgetContents);

                    plotContent->setMinimumWidth(150);
                    //plotContent->setMinimumHeight(300);
                    plotContent->setWordWrap(true);
                    plotContent->setAlignment(Qt::AlignJustify);
                    plotContent->setAlignment(Qt::AlignTop);
                    plotContent->setAlignment(Qt::AlignLeft);

                    plotHLayout->addWidget(plotContent);

                    insideVLayout->addItem(plotHLayout);
                    //------------end of plot------------------------------

                    //-------------rating-------------------------------------
                        QHBoxLayout* ratingHLayout = new QHBoxLayout(scrollAreaWidgetContents);
                        QLabel* ratingLabel = new QLabel("User Rating: ", scrollAreaWidgetContents);

                        ratingLabel->setMinimumWidth(120);
                        ratingLabel->setAlignment(Qt::AlignTop);
                        ratingLabel->setAlignment(Qt::AlignLeft);

                        ratingHLayout->addWidget(ratingLabel);


                        KRatingWidget* ratingContent = new KRatingWidget(scrollAreaWidgetContents);

                        ratingContent->setRating(mRated);

                        ratingContent->setMinimumWidth(150);
                        //ratingContent->setMinimumHeight(300);
                        //ratingContent->setWordWrap(true);
                        ratingContent->setAlignment(Qt::AlignJustify);
                        ratingContent->setAlignment(Qt::AlignTop);
                        ratingContent->setAlignment(Qt::AlignLeft);

                        ratingHLayout->addWidget(ratingContent);

                        insideVLayout->addItem(ratingHLayout);
                        //------------end of rating------------------------------

    tempHLayout->addItem(insideVLayout);
    return tempHLayout;


}

void MovieManager::populateResources()
{

}

#include "moviemanager.moc"
