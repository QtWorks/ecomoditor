#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Librerías Internas
#include "mainwindow_global.h"
#include "MainWindowEvents.h"
#include "MainWindowSignals.h"
#include "MainWindowSlots.h"

// Librerías Externas
#include "MenuBar.h"
#include "StatusBar.h"

// Librerías Qt
#include <QMainWindow>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace MainWindow {

        class MAINWINDOWSHARED_EXPORT MainWindow : public QMainWindow {

            Q_OBJECT

          public:
            explicit MainWindow ( QWidget *parent = 0 );
            ~MainWindow ();

          protected:
              void centerWindow ();
              virtual void changeEvent( QEvent *event );
              void closeEvent ( QCloseEvent *event );
              void createMenuBar ();
              void createStatusBar ();
              void init ();
              void loadSettins ();
              void resizeEvent ( QResizeEvent *event );
              void saveSettings ();
              void setMinimunWindowSize ();

          private:
              MainWindowEvents *mainWindowEvents;
              MainWindowSignals *mainWindowSignals;
              MainWindowSlots *mainWindowSlots;
        };
      }
    }
  }
}

#endif // MAINWINDOW_H
