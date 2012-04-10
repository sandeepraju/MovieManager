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


#include "nmm/movie.h"
#include "nfo/video.h"


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
#include <QHash>

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

    //getNepomukData();


    //MovieManager UI is setup here
    setupUserInterface();
    ///////////////////////////////







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
    //this->setMaximumSize(800,600);
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



    //adding the ListItem into the Main List!!
    //scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents));   //instead of passing this, make this the class datamember
    //scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents));

    //proposed function
    //for temporary purposes.


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

        /*Q_FOREACH( Nepomuk::Variant p ,pList)
        {
            qDebug() << "-------START---------";

            qDebug() << "-------END---------";
        }*/

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

    //scrollAreaVLayout->
    /*scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents,
                                                          QString("tavaralle"),QString("08-05-1991"),
                                                          QString("4"),QString("Comedy"),
                                                          QString("sadan"),QString("Swamy"),
                                                          QString("sumanth"),QString("The specification for the next stage is the output of the each design activity. This specification may be an abstract, formal specification that is produced to clarify the requirements or it may be a specification of how part of the system is to be realized."),
                                                          QUrl("file:///home/sandeep/.moviemanager/lagaan.jpg"),QString("2:30 mins"),
                                                          QString("3")));


    scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents,
                                                          QString("avatar"),QString("08-05-1991"),
                                                          QString("4"),QString("Comedy"),
                                                          QString("Vijesh"),QString("Swamy"),
                                                          QString("Vijay"),QString("hello world, this is PESIT"),
                                                          QUrl("file:///home/sandeep/.moviemanager/avatar2.jpg"),QString("2:30 mins"),
                                                          QString("3")));

    scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents,
                                                          QString("avatar"),QString("08-05-1991"),
                                                          QString("4"),QString("Comedy"),
                                                          QString("Vijesh"),QString("Swamy"),
                                                          QString("Vijay"),QString("hello world, this is PESIT"),
                                                          QUrl("file:///home/sandeep/.moviemanager/avatar2.jpg"),QString("2:30 mins"),
                                                          QString("3")));

    scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents,
                               createMovieManagerlistItem                           QString("avatar"),QString("08-05-1991"),
                                                          QString("4"),QString("Comedy"),
                                                          QString("Vijesh"),QString("Swamy"),
                                                          QString("Vijay"),QString("hello world, this is PESIT"),
                                                          QUrl("file:///home/sandeep/.moviemanager/avatar2.jpg"),QString("2:30 mins"),
                                                          QString("3")));
    */
    //scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents,"avatar","08-05-1991","4","Comedy","Vijesh","Swamy", "Vijay","hello world, this is PESIT",QUrl("/home/sandeep/.moviemanager/avatar2.jpg"),"2:30 mins","3"));
    //, QString mTitle, QString mReleased, QString mRated, QString mGenre, QString mDirector, QString mWriter, QString mActors, QString mPlot, QUrl mPoster, QString mRuntime, QString mIMDBRating
    hBottomLayout->addItem(vLayout);

    setCentralWidget(mainWindow);



}

//user defined slots here...

void MovieManager::slotSearchBarTextChanged(QString userInput)
{
    //qDebug("user is typing this >> ");
    qDebug(userInput.toLatin1().data());    //this is generating some warning



    //query nepomuk or from the results already generated and display appropriate things in the list!

//    int count = 0;
//    Q_FOREACH( const Nepomuk::Query::Result& globalResult, globalResults) {
//        qDebug() << count;

//        if(globalResult.resource().genericLabel().contains(userInput) == false)
//        {

//            //QHBoxLayout* tempRef;
//            qDebug() << "count inside if"<< count;

//            scrollAreaVLayout->removeItem(resultListRef[count]);
    //scrollAreaVLayout->removeItem(resultListRef[0]);
    QLayoutItem *child;
     /*while ((*/child = scrollAreaVLayout->takeAt(0);/*) != 0) {*/

         //delete child;
//     }
    //;
    //delete resultListRef[0];
    //scrollAreaVLayout->removeItem(resultListRef[1]);
//    scrollAreaVLayout->removeItem(resultListRef[2]);
//    scrollAreaVLayout->removeItem(resultListRef[3]);
//    scrollAreaVLayout->removeItem(resultListRef[4]);
//    scrollAreaVLayout->removeItem(resultListRef[5]);
//    scrollAreaVLayout->removeItem(resultListRef[6]);
//    scrollAreaVLayout->removeItem(resultListRef[7]);
//    scrollAreaVLayout->removeItem(resultListRef[8]);
//    scrollAreaVLayout->removeItem(resultListRef[9]);
//    scrollAreaVLayout->removeItem(resultListRef[10]);
//    scrollAreaVLayout->removeItem(resultListRef[11]);
//    scrollAreaVLayout->removeItem(resultListRef[12]);
//    //scrollAreaVLayout->removeItem(resultListRef[13]);

//            count++;
//            //resultListRef.push_back(tempRef);
//        }

//    }


    /*scrollAreaVLayout->addItem(createMovieManagerlistItem(scrollAreaWidgetContents,
                                                          QString("SANDEEP RAJU P"),QString("08-05-1991"),
                                                          QString("4"),QString("Comedy"),
                                                          QString("Fun"),QString("Hahaha"),
                                                          QString("sumanth"),QString("The specification for the next stage is the output of the each design activity. This specification may be an abstract, formal specification that is produced to clarify the requirements or it may be a specification of how part of the system is to be realized."),
                                                          QUrl("file:///home/sandeep/.moviemanager/lagaan.jpg"),QString("2:30 mins"),
                                                          QString("3")));
*/

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

            //Nepomuk::Resource tempActor;
            //tempActor.addType(Nepomuk::Vocabulary::NCO::Contact());
            //tempActor.setLabel(QString("Phaneendra hegde"));

            //result.resource().setProperty(Nepomuk::Vocabulary::NMM::actor(),tempActor);

            //qDebug() << "actor is set...";

             //the latest actor will be added to actor field.. so..
             //need to create a actor variant list and sent it instead?

            //Nepomuk::Resource tempActor2;
            //tempActor2.addType(Nepomuk::Vocabulary::NCO::Contact());
            //tempActor2.setLabel(QString("Phalgun Guduthur"));

            //result.resource().setProperty(Nepomuk::Vocabulary::NMM::actor(),tempActor2);

            //qDebug() << "actor is set... again";

            Nepomuk::Resource* tempImage = new Nepomuk::Resource("/home/sandeep/.moviemanager/lagaan.jpg");
            tempImage->addType(Nepomuk::Vocabulary::NFO::Image());
            //tempActor.set

            result.resource().setProperty(Nepomuk::Vocabulary::NMM::artwork(),*tempImage);

            //result.resource().setProperty(Nepomuk::Vocabulary::NFO::FileHash(),*tempImage);

            qDebug() << "POSTER URL>>>>>>>> " << result.resource().property(Nepomuk::Vocabulary::NMM::artwork()).toString();


            //result.resource().setRating(4);




        }
        /*else {
            qDebug()<< result.resource().property(Nepomuk::Vocabulary::NMM::actor()).toString() << "else";
        }*/
        //**FOR LOOP ENDS HERE

    }


    //-----------------------END OF CODE-------------------------------------------

    //Nepomuk::Resource *test = new Nepomuk::Resource("/home/sandeep/Videos/Gracie.avi");
    //test->addType(Nepomuk::Vocabulary::NMM::Movie());
    //test->setRating(4);

    //Nepomuk::NMM::Movie *mov = new Nepomuk::NMM::Movie(QUrl("/home/sandeep/Videos/Gracie.avi"));

    //Nepomuk::NFO::Video *hello = new Nepomuk::NFO::Video(QUrl("/home/sandeep/Videos/Gracie.avi"));



    //mov->setActor();

    // Nepomuk::Vocabulary::NMM *tes = new Nepomuk::Vocabulary::NMM::Movie();


    //-------old query------------------------------------------
    /*Nepomuk::Query::Term term =  Nepomuk::Query::ResourceTypeTerm( Nepomuk::Vocabulary::NFO::Video());*/            /* ||
                Nepomuk::Query::ComparisonTerm(Nepomuk::Vocabulary::NIE::mimeType(),
                                                   Nepomuk::Query::LiteralTerm(QLatin1String("video"))*);*/

    //-----------end of old query ------------------------------------
    //Nepomuk::Query::Query m_currentQuery;
    //m_currentQuery.setTerm(term);
    //m_currentQuery.setLimit( 30 );
    //qDebug()<<m_currentQuery.toSparqlQuery();
    //QList<Nepomuk::Query::Result> results = Nepomuk::Query::QueryServiceClient::syncQuery( m_currentQuery );
    //QList<Nepomuk::Resource> resources;
    /*
    Q_FOREACH( const Nepomuk::Query::Result& result,results) {
        //addIconToResource(result.resource());
        //qDebug()<<result.resource().genericLabel();


        QString temp(result.resource().genericLabel().remove(result.resource().genericLabel().length()-4,4));



        //s.remove(1, 4);
        if(temp.contains("KDE") != true)
        {
            //This if condition should be removed
            qDebug(temp.toLatin1().data());
            qDebug(result.resource().type().toLatin1().data());
            //qDebug(result.resource().property(Nepomuk::Vocabulary::NIE::url()).toString().toLatin1().data());

            if(result.resource().property(Nepomuk::Vocabulary::NMM::actor()).toString().length() > 0)
            {
                //Newly indexed, data not fetched!
                //goto imdb and fetch the data
            }
            else
            {

            }


            //Nepomuk::NFO::Video::
           result.resource().setProperty(Nepomuk::Vocabulary::NMM::actor(),"Rajnikanth");

             qDebug(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.");
             //qDebug(result.resource().property("Nepomuk::NMM::actor()").toString().toLatin1().data());
             qDebug()<< result.resource().property(Nepomuk::Vocabulary::NMM::actor()).toString();
             qDebug("******************************************.");

            IMDB* imdb = new IMDB(temp.toLatin1().data());
            imdb->getData();
            qDebug("finished fetching");
        }

        //resources.append( result.resource() );
    }*/
    //resourceSort(resources);
    //m_resourceViewModel->setResources( resources );


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

    /*QWebView* poster = new QWebView(scrollAreaWidgetContents);
    poster->load(mPoster);
    //poster->load(QUrl("file:///home/sandeep/.moviemanager/avatar2.jpg"));
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

    /*QHBoxLayout* testHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    testHLayout->addWidget(new QLabel("Title: ", scrollAreaWidgetContents));
    QLabel* tempLabel = new QLabel("Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy");
    //QLabel* tempLabel = new QLabel(mPlot);
    //tempLabel->setWordWrap(true);
    tempLabel->setAlignment(Qt::AlignRight);
    tempLabel->setAlignment(Qt::AlignTop);
    tempLabel->setFixedWidth(300);
    tempLabel->setFixedHeight(100);
    //tempLabel->setMinimumWidth(200);
    testHLayout->addWidget(tempLabel);*/

   /* QHBoxLayout* nameHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    nameHLayout->addWidget(new QLabel("Title: ", scrollAreaWidgetContents));
    nameHLayout->addWidget(new QLabel(mTitle, scrollAreaWidgetContents));

    QHBoxLayout* actorHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    actorHLayout->addWidget(new QLabel("Actor: ", scrollAreaWidgetContents));
    actorHLayout->addWidget(new QLabel(mActors, scrollAreaWidgetContents));

    QHBoxLayout* directorHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    directorHLayout->addWidget(new QLabel("Director: ", scrollAreaWidgetContents));
    directorHLayout->addWidget(new QLabel(mDirector, scrollAreaWidgetContents));

    QHBoxLayout* writerHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    writerHLayout->addWidget(new QLabel("Writer: ", scrollAreaWidgetContents));
    writerHLayout->addWidget(new QLabel(mWriter, scrollAreaWidgetContents));

    QHBoxLayout* plotHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    plotHLayout->addWidget(new QLabel("Plot: ", scrollAreaWidgetContents));
    plotHLayout->addWidget(new QLabel(mTitle, scrollAreaWidgetContents));


    //adding the rating widget
    QHBoxLayout* ratingHLayout = new QHBoxLayout(scrollAreaWidgetContents);
    ratingHLayout->addWidget(new QLabel("Rating: ", scrollAreaWidgetContents));
    ratingHLayout->addWidget(new KRatingWidget(scrollAreaWidgetContents));

    //insideVLayout->addItem(testHLayout);
    insideVLayout->addItem(nameHLayout);
    insideVLayout->addItem(actorHLayout);
    insideVLayout->addItem(directorHLayout);
    insideVLayout->addItem(writerHLayout);
    insideVLayout->addItem(plotHLayout);
    insideVLayout->addItem(ratingHLayout);

    //finally adding the metadata layout to the ListItem
    tempHLayout->addItem(insideVLayout);*/


    //------------- list item generator ends--------------------------------
    //-------------- tempHLayout should be returned ------------------------

    //+++++++++++++++++++++++   IDEAL ITEM    ++++++++++++++++++++++++++++++


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
    /*
    //-------------line1a-------------------------------------
    QHBoxLayout* itemHLayout1a = new QHBoxLayout(helloWidget);
    QLabel* idLabel1a = new QLabel("Id: ",helloWidget);

    idLabel1a->setMinimumWidth(120);
    idLabel1a->setAlignment(Qt::AlignTop);
    idLabel1a->setAlignment(Qt::AlignLeft);

    itemHLayout1a->addWidget(idLabel1a);
    QLabel* idContent1a = new QLabel("The specification for the next stage is the output of the each design activity. This specification may be an abstract, formal specification that is produced to clarify the requirements or it may be a specification of how part of the system is to be realized.",helloWidget);

    idContent1a->setMinimumWidth(150);
    idContent1a->setMinimumHeight(300);
    idContent1a->setWordWrap(true);
    idContent1a->setAlignment(Qt::AlignJustify);
    idContent1a->setAlignment(Qt::AlignTop);
    idContent1a->setAlignment(Qt::AlignLeft);

    itemHLayout1a->addWidget(idContent1a);
    innerVLayout->addItem(itemHLayout1a);
    //------------end of line 1a------------------------------
    */

    /*
    //-------------line1-------------------------------------
    QHBoxLayout* item2HLayout = new QHBoxLayout(helloWidget);
    item2HLayout->addWidget(new QLabel("Title: ",helloWidget));
    item2HLayout->addWidget(new QLabel("Avatar",helloWidget));
    innerVLayout->addItem(item2HLayout);
    //-------------end of line1------------------------------
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    */
    tempHLayout->addItem(insideVLayout);
    return tempHLayout;


}

void MovieManager::populateResources()
{

}

#include "moviemanager.moc"
