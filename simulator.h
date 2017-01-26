#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <collision_library.h>
#include <gmParametricsModule>
#include <vector>
using DynSphere =
    collision::DynamicPhysObject<GMlib::PSphere<float>>;
using Plane =
    collision::StaticPhysObject<GMlib::PPlane<float>>;

using DynSpherePtrVector = std::vector<DynSphere*>;
using DynPlanePtrVector = std::vector<Plane*>;

using DynSphereVector = std::vector<std::unique_ptr<DynSphere>>;
using DynPlaneVector = std::vector<std::unique_ptr<Plane>>;
/*
class SimulationController : public GMlib::SceneObject {
  GM_SCENEOBJECT(SimulationController)
public:
  SimulationController() = default;

  void add (DynSphere* const sphere );
  void add (Plane* const plane);
protected:
  void localSimulate(double dt) override final;

private:
  DynSpherePtrVector _dspheres;
  DynPlanePtrVector _planes;
  collision::DefaultEnvironment _environment;
};
*/
class Simulator {
public:
    explicit Simulator( GMlib::Scene& scene);
    void setupSimulator();

private:

    GMlib::Scene& _scene;
    collision::MyController _controller;
    DynSphereVector _dspheres;
    DynPlaneVector _planes;

    template <typename T>
    void prepareAndInsert(const std::unique_ptr<T>& obj, int m1,int m2, int d1, int d2);
};



template <typename T>
inline
void Simulator::prepareAndInsert (const std::unique_ptr<T>& obj, int m1,int m2, int d1, int d2){

 obj->toggleDefaultVisualizer();
 obj->replot(m1,m2,d1,d2);
 _scene.insert(obj.get());
 _controller.add(obj.get());
}

#endif // SIMULATOR_H
