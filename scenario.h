#ifndef SCENARIO_H
#define SCENARIO_H


#include "application/gmlibwrapper.h"
class Simulator;
// qt
#include <QObject>
//stl
#include <memory>


class Scenario : public GMlibWrapper {
  Q_OBJECT
public:
  using GMlibWrapper::GMlibWrapper;

  void    initializeScenario() override;
  void    cleanupScenario() override;
private:
    std::shared_ptr<Simulator> _simulator;
};

#endif // SCENARIO_H
