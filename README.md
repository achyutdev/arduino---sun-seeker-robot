Arduino---Sun-Seeker-Robot
=========================
This programming script is for robotic body that carry solar pannel and move its pannel toward the direction of light  in order to absorpt more amount of solar energy. This Robot has two light sensor which is kept at the edge of panel. Both sensor detect light only when panel is perpandicular to light of sun. There are three condition:

####1. Both sensor detect light
when both sensor detect light it `stop_right_there`.

####2. One of the sensor detect light
Robot starts to rotate panel toward the sensor which detect light using `rotate_in_dir_of_light` function.Thus there is a chance of detecting light for both sensor. which is first condition `stop_right_there`.

####3. Both sensor does not detect light
Robot move predefine one square path- `move_forward_searching_light`, if it detects light on the way then it works on one of the above condition. After completion of one full rotation it stop.

##Uses
* to absorp maximun solar energy from rooftop solar panel
* to any solar power robotic device
