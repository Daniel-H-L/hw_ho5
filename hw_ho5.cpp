#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/PlanManeuver.hpp>
#include <IMC/Spec/Loiter.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/EntityParameter.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
//#include <UDP/DatagramSocket.h>
#define LAUVXPLORE1 (30)
using namespace IMC;

int main() {
    char localhost[] = "127.0.0.1";
    PlanSpecification planspecification;
    planspecification.setTimeStamp(1.5628304294681385E9);
    planspecification.setSource(16652);
    planspecification.setSourceEntity(44);
    planspecification.setDestination(30); 
    planspecification.setDestinationEntity(255);
    planspecification.plan_id = "cmd-lauv-xplore-1";
    planspecification.start_man_id = "1";

    PlanManeuver planmaneuver;
    planmaneuver.maneuver_id = "1";
    Loiter Loiter;
    planmaneuver.data = Loiter
    // Loiter loiter;
    // loiter.timeout = 10000;
    // loiter.lat = 0.7188016469344056;
    // loiter.lon = -0.15194250254286037;
    // loiter.z = 3;
    // loiter.z_units = 1;
    // loiter.duration = 300;
    // loiter.speed = 1000;
    // loiter.speed_units = 1;
    // loiter.type = 1;
    // loiter.radius = 20;
    // loiter.bearing = 0;
    // loiter.direction = 1;
    
    

    planspecification.maneuvers = [planmaneuver];

    SetEntityParameters setentparams;
    setentparams.name = LBL;
    
    EntityParameter entparam;
    entparam.name = Active;
    entparam.value = false;

    planspecification.start_actions = [setentparams, entparam]


    int size = planspecification.getSerializationSize();    // calculate bytes required for serialization
    char buffer[size];                          // allocate same number of bytes
    
    Packet::serialize(&abort, (uint8_t *) buffer, size);    // serialize message
    DatagramSocket socket(6002, localhost, true, true);     // see https://github.com/butcherg/DatagramSocket
    socket.sendTo(buffer, size, localhost);                 // send message to 127.0.0.1:6002
}
