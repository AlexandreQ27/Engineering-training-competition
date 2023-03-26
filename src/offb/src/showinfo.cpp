#include <state_from_mavros.h>

int main(int argc, char **argv)
{
    int header = 1;
    ros::init(argc, argv, "showinfo_node");
    ros::NodeHandle nh;
    ros::Rate rate(20.0);
    state_from_mavros state_from_mavros_;
    while(ros::ok())
    {
        cout << "header:" << header << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<无人机当前状态<<<<<<<<<<<<<<<"<<endl;
        if(state_from_mavros_._DroneState.connected)
        {
            cout << "connected: true" ;
        }
        else{
            cout << "connected:false" ;
        }
        cout << endl;
        if(state_from_mavros_._DroneState.armed)
        {
            cout << "armed:true";
        }
        else{
            cout << "armed:false";
        }
        cout << endl;
        cout << "无人机当前模式:" << state_from_mavros_._DroneState.mode<< endl;
        cout <<"<<<<<<<<<<<<<<<<<<<<<无人机当前位置<<<<<<<<<<<<" << endl;
        cout << state_from_mavros_._DroneState.position[0]<<"         "
                    <<state_from_mavros_._DroneState.position[1] <<"       "
                    <<state_from_mavros_._DroneState.position[2] << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<无人机当前速度<<<<<<<<<<<<<<<<<" << endl;
        cout<<state_from_mavros_._DroneState.velocity[0] << "          "
                << state_from_mavros_._DroneState.velocity[1] << "          "
                << state_from_mavros_._DroneState.velocity[2] << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<无人机的欧拉角<<<<<<<<<<<<<<<<<"<< endl;
        cout << state_from_mavros_._DroneState.attitude_q.x <<  "         "
                  << state_from_mavros_._DroneState.attitude_q.y  <<  "          "
                  <<  state_from_mavros_._DroneState.attitude_q.z << "           "
                  <<  state_from_mavros_._DroneState.attitude_q.w<< "           " << endl;
        cout << endl << endl;
        ros::spinOnce();
        rate.sleep();
        header++;
    }
}
