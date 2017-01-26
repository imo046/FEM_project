#include "simulator.h"

/*
void SimulationController::add(DynSphere * const sphere)
{
  sphere->environment = &_environment;
  _dspheres.push_back(sphere);
}

void SimulationController::add(Plane * const plane)
{
    _planes.push_back(plane);
}

void SimulationController::localSimulate(double dt)
{
    //add collision algorithm here
        for(auto sphere:_dspheres){
            sphere->simulateToTInDt(seconds_type(dt));
        }
}
*/
//void MyController::localSimulate(double dt)
//{
//Algorithm here ^^
//}


Simulator::Simulator(GMlib::Scene &scene): _scene{scene}
{
//_scene.insert(&_controller);
}

void Simulator::setupSimulator()
{
_dspheres.push_back(std::make_unique<DynSphere>());
_dspheres.back()->velocity = GMlib::Vector<double,3>(0.0f,2.0f,5.0f);
_dspheres.back()->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));

_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (-20.0f,-20.0f,10.0f),
                      GMlib::Vector<float,3> (40.0f,0.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (20.0f,-20.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,40.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,10.0f)
                  ));
//west
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (-20.0f,20.0f,10.0f),
                      GMlib::Vector<float,3> (0.0f,-40.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));
//north
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (20.0f,20.0f,10.0f),
                      GMlib::Vector<float,3> (-40.0f,0.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (-20.0f,-20.0f,0.0f),
                      GMlib::Vector<float,3> (40.0f,0.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,40.0f,0.0f)
                  ));
for (const auto& sphere:_dspheres)
    prepareAndInsert(sphere, 15,15, 1,1);

for (const auto& plane:_planes)
    prepareAndInsert(plane, 10,10,1,1);

_scene.insert(&_controller);
}

