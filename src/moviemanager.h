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

#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include "imdb.h"

#include <KXmlGuiWindow>
#include <KDE/KApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <KLineEdit>
#include <QLabel>
#include <KPushButton>
#include <QListView>
#include <QUrl>
#include<QScrollArea>
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

#include <QToolButton>
#include <QComboBox>

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
#include <Nepomuk/Query/AndTerm>
#include <Nepomuk/Query/OrTerm>
#include <Nepomuk/Query/ResourceTerm>
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


///////////////



//#include "ui_prefs_base.h"

//class MovieManagerView;
class QPrinter;
class KToggleAction;
class KUrl;

/**
 * This class serves as the main window for MovieManager.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author Sadan Sohan M <sadansohanm@gmail.com>
 * @version 0.0
 */
class MovieManager : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    MovieManager();

    /**
     * Default Destructor
     */
    virtual ~MovieManager();

private slots:
    void fileNew();
    void optionsPreferences();
    void slotQuitApplication();
    void slotSearchBarTextChanged(QString);
    void slotPlayVideo(QUrl);

private:

    void setupActions();
    void setupUserInterface();
    void getNepomukData();
    QHBoxLayout* createMovieManagerlistItem(QWidget*,
                                            QString mTitle, QString mReleased,
                                            quint32 mRated, QString mGenre,
                                            QString mDirector, QString mWriter,
                                            QString mActors, QString mPlot,
                                            QUrl mPoster, QString mRuntime,
                                            QString mIMDBRating);
    void populateResources();

private:
    QList<Nepomuk::Query::Result> globalResults;
    QWidget * scrollAreaWidgetContents;
    QVBoxLayout * scrollAreaVLayout;
    QList<QHBoxLayout*> resultListRef;
    //Ui::prefs_base ui_prefs_base ;
    //MovieManagerView *m_view;
    QScrollArea* mainListScroll;
    QPrinter   *m_printer;
    KToggleAction *m_toolbarAction;
    KToggleAction *m_statusbarAction;

    QWidget* mainWindow;
    QVBoxLayout* vMainLayout;
    QLabel* searchLabel;
    KLineEdit* searchBar;
    //KPushButton* searchButton;
    QListView* mainList;
    QListView* secondaryList;

    QHBoxLayout* hTopLayout;
    QHBoxLayout* hBottomLayout;

    //NEW CODE GOES HERE
    // m_resourceView == resultPanel
    QListView* resultPanel;
    Nepomuk::Utils::SimpleResourceModel* m_resourceViewModel;
private:
    void setupNewUserInterface();
    void setupNewModels();
    void populateDefaultResources();
    void addIconToResource(Nepomuk::Resource);
    void resourceSort(QList<Nepomuk::Resource> &resources);

private slots:
    void slotResultPanelSelectionChanged();
    void slotOpenResource(QModelIndex);
    //NEW CODE ENDS HERE
};

#endif // _MOVIEMANAGER_H_
