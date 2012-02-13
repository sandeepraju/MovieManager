set(QT_USE_QTNETWORK TRUE)

set(moviemanager_SRCS
   moviemanager.cpp
   main.cpp
   imdb.cpp
   qdownloader.cpp
 )

FIND_PACKAGE(QJSON)

############## from pnh cmake file ######
find_package(KDE4 REQUIRED)
find_package(Nepomuk REQUIRED)
find_package(NepomukExtras)
include(MacroLibrary)
include(SopranoAddOntology)
include (KDE4Defaults)
##########################################

#kde4_add_ui_files(moviemanager_SRCS moviemanagerview_base.ui prefs_base.ui)

kde4_add_kcfg_files(moviemanager_SRCS settings.kcfgc )

kde4_add_executable(moviemanager ${moviemanager_SRCS})

target_link_libraries(moviemanager ${KDE4_KDEUI_LIBS} )
target_link_libraries(moviemanager ${QT_QTWEBKIT_LIBRARY})
target_link_libraries(moviemanager ${QJSON_LIBRARIES})

install(TARGETS moviemanager ${INSTALL_TARGETS_DEFAULT_ARGS} )


########### from pnh cmake file #########
target_link_libraries( moviemanager
  nepomukutils
  nepomukextras
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
  ${NEPOMUK_LIBRARIES}
  ${NEPOMUK_QUERY_LIBRARIES}
  ${SOPRANO_LIBRARIES}
  ${NEPOMUKEXTRAS_INCLUDE_DIR}
  )

#########################################

########### install files ###############

install( PROGRAMS moviemanager.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES moviemanager.kcfg  DESTINATION  ${KCFG_INSTALL_DIR} )
install( FILES moviemanagerui.rc  DESTINATION  ${DATA_INSTALL_DIR}/moviemanager )
