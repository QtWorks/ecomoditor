#ifndef MENUBAR_H
#define MENUBAR_H

#include "menubar_global.h"

#include <QMenuBar>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Menubar {

          class MENUBARSHARED_EXPORT MenuBar : public QMenuBar {

              Q_OBJECT

            public:
              explicit MenuBar ( QWidget *parent = 0  );
              ~MenuBar ();
          };
        }
      }
    }
  }
}

#endif // MENUBAR_H
