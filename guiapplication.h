#ifndef GUIAPPLICATION_H
#define GUIAPPLICATION_H


//#include <standardhidmanager.h>

// qt
#include <QGuiApplication>

// stl
#include <memory>


class Window;
class GMlibWrapper;


class GuiApplication : public QGuiApplication {
  Q_OBJECT
public:
  explicit GuiApplication(int& argc, char* argv[]);

private:
  std::shared_ptr<Window>         _window;
  std::shared_ptr<GMlibWrapper>   _gmlib;

private slots:
  void                        onSGInit();

private:
  static std::unique_ptr<GuiApplication>    _instance;
public:
  static const GuiApplication&            getInstance();
};

#endif // GUIAPPLICATION_H
