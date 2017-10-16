#include "AppPaths.h"

using namespace Com::Ecosoftware::App;

AppPaths::AppPaths () {

  QString userPathApp = QDir::homePath () + QDir::separator() + ".ecosoftware" + QDir::separator() + "ecomoditor" + QDir::separator();
  this->applicationDirPath = new QDir ( QCoreApplication::applicationDirPath () );
  this->applicationPathRoot = this->applicationDirPath->absolutePath () + QDir::separator();
  this->applicationDirPath->cdUp ();
  this->applicationPath = this->applicationDirPath->absolutePath () + QDir::separator();
  this->applicationConfigPath = userPathApp + "config" + QDir::separator();
  this->applicationDataPath = userPathApp + "data" + QDir::separator();
  this->applicationImagePath = this->getApplicationPath () + QDir::separator() + "images" + QDir::separator();
  this->applicationLanguagePath = userPathApp + "language" + QDir::separator();
  this->applicationResourcesPath = this->getApplicationPath () + QDir::separator() + "resources" + QDir::separator();
  this->applicationTempPath = userPathApp + "temp" + QDir::separator();
  this->applicationWorkspacePath = QDir::homePath () + QDir::separator() + "ecomoditor" + QDir::separator();
  this->xsdPath = this->getApplicationPath () + QDir::separator() + "data" + QDir::separator() + "MANIFEST.xsd";
}

AppPaths::~AppPaths () {}

QString AppPaths::getApplicationConfigPath () const {

  return this->applicationConfigPath;
}

QString AppPaths::getApplicationDataPath () const {

  return this->applicationDataPath;
}

QString AppPaths::getApplicationImagePath () const {

  return this->applicationImagePath;
}

QString AppPaths::getApplicationLanguagePath () const {

  return this->applicationLanguagePath;
}

QString AppPaths::getApplicationPath () const {

  return this->applicationPath;
}

QString AppPaths::getApplicationPathRoot () const {

  return this->applicationPathRoot;
}

QString AppPaths::getApplicationResourcesPath () const {

  return this->applicationResourcesPath;
}

QString AppPaths::getApplicationTempPath () const {

  return this->applicationTempPath;
}

QString AppPaths::getApplicationWorkspacePath () const {

  return this->applicationWorkspacePath;
}

QString AppPaths::getXsdPath () const {

  return this->xsdPath;
}

AppPaths &AppPaths::getInstance () {

  static AppPaths instance;
  return instance;
}
