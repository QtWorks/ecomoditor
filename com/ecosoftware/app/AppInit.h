#ifndef APPINIT_H
#define APPINIT_H

// Librerías internas
#include "app_global.h"

// Librerías Qt
#include <QDebug>
#include <QDockWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QMap>
#include <QString>
#include <QVariant>

namespace Com {

  namespace Ecosoftware {

    namespace App {

      class APPSHARED_EXPORT AppInit {

        public:
          static bool checkVersion ();
          static void loadSettings ();
          static bool restoreDockWidget ( QMainWindow *parent, QDockWidget *dockWidget );
          static bool restoreGeometry ( QMainWindow *parent );
          static bool restoreState ( QMainWindow *parent );
          static void saveSettings ();
          static void saveState ( QMainWindow *parent );
      };
    }
  }
}

#endif // APPINIT_H
