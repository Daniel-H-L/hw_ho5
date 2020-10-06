#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/PlanManeuver.hpp>
#include <IMC/Spec/Loiter.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/EntityParameter.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#include <UDP/DatagramSocket.h>

#include <iostream>
#include <fstream> 

//#define LAUVXPLORE1 (30)
using namespace IMC;

int main() {
    std::cout << "Start main";


    PlanSpecification planspecification;
    planspecification.setTimeStamp(1.5628304294681385E9);
    planspecification.setSource(16652);
    planspecification.setSourceEntity(44);
    planspecification.setDestination(30); 
    planspecification.setDestinationEntity(255);
    planspecification.plan_id = "cmd-lauv-xplore-1";
    //planspecification.description = "";     REMOVE?
    //planspecification.vnamespace = "";
    planspecification.start_man_id = "1";


    PlanManeuver planmaneuver;
    planmaneuver.maneuver_id = "1";

    // How do i set the Loiter data??
    
    //Loiter Loiter;
    
    // planmaneuver.data = Loiter
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
    

    // Different try, still don't understand this:

    InlineMessage<Maneuver> data;
    planspecification.maneuvers.push_back(&planmaneuver);

    
    char localhost[] = "127.0.0.1";
    int size = planspecification.getSerializationSize();
    char buffer[size];
    int port = 6002;

    Packet packet;
    packet.serialize(&planspecification, (uint8_t *) buffer, size);
    DatagramSocket socket(port, localhost, true, true);
    socket.sendTo(buffer, size, localhost);


    // Writing to disk as JSON:
    std::filebuf fb;
    fb.open ("json_out.txt",std::ios::out);
    std::ostream os(&fb);
    planspecification.toJSON(os);
    fb.close();


    std::cout << "End main";
}
