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
#include <KDE/KApplication>
#include <KDE/KAboutData>
#include <KDE/KCmdLineArgs>
#include <KDE/KLocale>


static const char description[] =
    I18N_NOOP("A KDE 4 Application");

static const char version[] = "0.0";

int main(int argc, char **argv)
{
    KAboutData about("moviemanager", 0, ki18n("MovieManager"), version, ki18n(description),
                     KAboutData::License_GPL, ki18n("(C) 2012 Sandeep Raju P & Sadan Sohan M"), KLocalizedString(), 0, "sandeep080@gmail.com\nsadansohanm@gmail.com");
    about.addAuthor( ki18n("Sandeep Raju P"), KLocalizedString(), "sandeep080@gmail.com" );
    about.addAuthor( ki18n("Sadan Sohan M"), KLocalizedString(), "sadansohanm@gmail.com" );
    KCmdLineArgs::init(argc, argv, &about);

    KCmdLineOptions options;
    options.add("+[URL]", ki18n( "Document to open" ));
    KCmdLineArgs::addCmdLineOptions(options);
    KApplication app;

    MovieManager *widget = new MovieManager();

    // see if we are starting with session management
    if (app.isSessionRestored())
    {
        RESTORE(MovieManager);
    }
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
        if (args->count() == 0)
        {
            //moviemanager *widget = new moviemanager;
            //widget->setMaximumSize(200,200);
            widget->show();
            //mainListScroll->show();
           // widget->mainListScroll->show();

        }
        else
        {
            int i = 0;
            for (; i < args->count(); i++)
            {
                //moviemanager *widget = new moviemanager;
                //widget->setMaximumSize(200,200);
                widget->show();
                //widget->mainListScroll->show();
            }
        }
        args->clear();
    }

    return app.exec();
}
