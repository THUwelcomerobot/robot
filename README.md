# Robot for new comers from DA.THU
#### based on qizhi ROS robot from 6-robot company

####  1.  commucation block 
how to run:
```
roslaunch xbchat xbchatter.launch
```
   **this block is based on Microsoft AI chatter Xiaobing and itchat API, to use it you have to scan the qr code when it jumps out and comfirm, then you may talk to it.**             

#### 2. control block 
- js control
how to run:
```
roslaunch wpb_home_bringup js_ctrl.launch           
```
- touchpad control     
**based on gui and rostopic , actually it runs**
```
roslaunch wpb_home_bringup minimal.launch
```
then pub rostopic to control
```
rostopic pub /cmd_vel geometry_msgs/Twist + [your vel]
```
- keyboard control 
how to run 
```
roslaunch mobilecontrol mobi_control.launch 
```
**use 'w' 's' 'a' 'd' to control ,on key press one time once **
#### 3.SLAM 
**to SLAM with motors off,run**
```
 roslaunch wpb_home_tutorials hector_mapping.launch 
```
**to SLAM with motors on and use js control,run**
```
roslaunch wpb_home_tutorials gmapping.launch 
```
after SLAM done,run 
```
 rosrun map_server map_saver -f map
```
to save your map, and copy your **map.pgm**,**map.yaml** from **/home/robot** to **/home/robot/catkin_ws/src/wpb_home/wpb_home_tutorials/maps/** 
