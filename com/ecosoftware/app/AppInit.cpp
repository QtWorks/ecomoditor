#include "AppInit.h"
#include "AppSettings.h"

#include <QIODevice>
#include <QSettings>
#include <QtXml>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <stdlib.h>

#include <QDebug>

using namespace Com::Ecosoftware::App;

bool AppInit::checkVersion () {

  if ( QT_VERSION < QT_VERSION_CHECK ( 5, 0, 0 ) ) {

    QMessageBox msgBox ( QMessageBox::Warning, "Ecomoditor", "Debe tener instalada una versión de Qt igual o superior 5.0.0.", 0 );
    msgBox.exec ();
    return false;
  }
  return true;
}

void AppInit::loadSettings () {

  //const QSettings::Format XmlFormat = QSettings::registerFormat ( "xml", ( QSettings::ReadFunc ) AppSettings::readXmlFile, ( QSettings::WriteFunc ) AppSettings::writeXmlFile );
  //QSettings settings ( XmlFormat, QSettings::UserScope, "ecosoftware", "ecomodeditor" );
  //settings.setPath ( XmlFormat, QSettings::UserScope, ".ecosoftware" );

  //return settings;
}

bool AppInit::restoreDockWidget ( QMainWindow *parent , QDockWidget *dockWidget ) {

    //QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
    return parent->restoreDockWidget ( dockWidget );
}

bool AppInit::restoreGeometry ( QMainWindow *parent ) {

    QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
    return parent->restoreGeometry ( settings.value ( "geometry" ).toByteArray () );
}

bool AppInit::restoreState ( QMainWindow *parent ) {

    QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
    return parent->restoreState ( settings.value ( "windowState" ).toByteArray () );
}

void AppInit::saveSettings () {

}

void AppInit::saveState ( QMainWindow *parent ) {

    QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
    //settings.setValue ( "dockWidget", parent->saveState () );
    settings.setValue ( "geometry", parent->saveGeometry () );
    settings.setValue ( "windowState", parent->saveState () );
}
