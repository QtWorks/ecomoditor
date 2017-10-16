// Librerías Internas
#include "VentanaPrincipal.h"

// Librerías Externas
#include "AppInit.h"
#include "AppPaths.h"
#include "AppSettings.h"
#include "SingleInstance.h"

// Librerías Qt
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

int main ( int argc, char *argv [] ) {

  QApplication appInstance ( argc, argv );

  const QSettings::Format XmlFormat = QSettings::registerFormat ( "xml", ( QSettings::ReadFunc ) Com::Ecosoftware::App::AppSettings::readXmlFile, ( QSettings::WriteFunc ) Com::Ecosoftware::App::AppSettings::writeXmlFile );
  QSettings settings ( Com::Ecosoftware::App::AppPaths::getInstance ().getApplicationDataPath ()+ "config/config.xml", XmlFormat );
  qDebug () << Com::Ecosoftware::App::AppPaths::getInstance ().getApplicationDataPath ()+ "config/config.xml";

  if ( !Com::Ecosoftware::App::AppInit::checkVersion () ) {

    return 0;
  }

  qDebug () << settings.value ( "ecomoditor/applicationhashkey" ).toString ();
  qDebug () << settings.value ( "ecomoditor/organizationname" ).toString ();
  qDebug () << settings.value ( "ecomoditor/organizationdomain" ).toString ();
  qDebug () << settings.value ( "ecomoditor/applicationname" ).toString ();
  qDebug () << settings.value ( "ecomoditor/applicationdisplayname" ).toString ();
  qDebug () << settings.value ( "ecomoditor/applicationversion" ).toString ();

  Com::Ecosoftware::SingleInstance::SingleInstance singleInstance ( settings.value ( "ecomoditor/applicationhashkey" ).toString () );

  appInstance.setOrganizationName ( settings.value ( "ecomoditor/organizationname" ).toString () );
  appInstance.setOrganizationDomain ( settings.value ( "ecomoditor/organizationdomain" ).toString () );
  appInstance.setApplicationName ( settings.value ( "ecomoditor/applicationname" ).toString () );
  appInstance.setApplicationDisplayName ( settings.value ( "ecomoditor/applicationdisplayname" ).toString () );
  appInstance.setApplicationVersion ( settings.value ( "ecomoditor/applicationversion" ).toString () );

  if ( !singleInstance.tryToRun () ) {

    QMessageBox msgBox ( QMessageBox::Warning, appInstance.applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", 0 );
    msgBox.exec ();
    return 0;
  }
  VentanaPrincipal mainWindow;
  mainWindow.show ();

  return appInstance.exec ();
}
