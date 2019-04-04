# Project90-Go-Baby-Go

Instructions for modifying variable quantities in the code file GOBABYGO_SabertoothSimplified_DriveCode.ino

*Important note: Do not edit variables or code beyond the commented warning:*
/****************************************************************/
/* DO NOT EDIT PAST THIS POINT UNLESS EXPLICITLY NEEDED         */
/****************************************************************/
*This code works and unless specific changes are needed, only the variables preceding this comment
should need to be changed for customizatoin.*

##Control Method/Option Setup:
Modify the boolean values under this header to specify the control methods for the vehicle.

##Invert Motor Directions:
Modify the boolean values under this header to change a motor direction, if it is inverted.

##Analogue Joystick Input Designation:
Modify the integer values under this header to change the pin destinations corresponding to
the numbered pin locations on the arduino board for the x and y axis inputs from the joystick.

##Button Control Input Designation:
Modify the integer values under this header to change the pin destinations corresponding to
the numbered pin locations on the arduino board for the directional button control inputs.

##Constants:
Adjust the max speed integer value in the range from 0 to 127. Based on tests, a value of 
30-40 is typically sufficient.

Adjust the pot neutral integer value to change the amount of tolerance in the joystick controls
ie. lower value means slight movements in joystick will still be output to motors, while higher
values means the joystick requires more pronounced movement to output to motors. Note that a
value of around 40 eliminates the input noise associated with the pot and should not be lowered
much below 20.

