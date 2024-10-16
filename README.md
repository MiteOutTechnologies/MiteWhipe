# MiteWhipe
One Line Pitch: 
  For beekeepers worldwide who have experienced hive loss from varroa mites, the MiteWhipe is a hive-retrofittable device that offers fully autonomous chemical treatments to ensure more effective eradication of varroa mites at a cheaper cost and easier application than any other treatment on the market.

Extended Pitch: 
  Our pollinators are dying. In 2020-2021, the honeybee, one of the most crucial pollinators, had a mortality rate of 50.8%, an alarming increase from the average of 39.6% over the past 12 years. Pollination from honeybees accounts for 15 billion dollars of US agricultural revenue every season; for the future of the economy and environment, we must work to stabilize this declining population before it meets its breaking point.
  Honeybees face many factors that drive their numbers down; the most pressing problem is the varroa mite. Nicknamed the “destructor mite”, this tiny external parasite plagues hives by feeding on bees, leaving hives weak and susceptible to viruses. Over time, beekeepers have developed chemical miticides that can be dosed in hives to eradicate the varroa mite; however, numerous issues with treatments emerged over time. Overuse of chemicals were found to negatively affect honey production and hive health, and others were ineffective or deadly to hives in certain temperature ranges. Additionally, beekeepers struggle to treat mites consistently, leading to increased mite numbers.
  For beekeepers worldwide who have experienced hive loss from varroa mites, MiteOut Technologies’ MiteWhipe is a device that offers fully autonomous precision treatments to ensure more effective eradication of varroa mites at a cheaper cost and easier application than any other treatment on the market. The Mitewhipe uses sensors to read hive temperature and gives precision micro doses of chemicals needed for the hive in that moment. 

What is the Technology?: 
  In short, it's an autonomous pesticide doser for beekeepers. System reads temperature and humidity readings and doses chemicals accordingly.

Background About the Project: 
  My name is Jonah Hymes, I’m a freshman at Dartmouth college studying computer engineering. I’ve been interested in robotics and mechatronics for most of my life so it was only natural that I adopted the title of CTO while working on the MiteWhipe. I’m working on this project my business partner, Lucas Bell, a childhood friend who's studying mechanical engineering at Rensselaer Polytechnic Institute. We’ve been developing this project for a year and a half and are currently submitting for a provisional patent. We’ve presented our project at the Thomas Edison Pitch Contest, a worldwide engineering competition where we placed second and earned the Most Innovative Use of Sustainable Energy award. We also presented at the Siena College Business Plan Competition, a more local competition where we placed first. Because of the work on the patent, we’ll be unable to fully disclose super specific details about the system.

Summary video: 
  Video recorded in January submitted to the Thomas Edison pitch contest, a few facts about the prototype are outdated, but the general concept still stands
[MiteOut - Saving the Bees](https://youtu.be/XGiNIPwtm90)

#Hardware: 
Main systems:
Hardware / Sensor
Real time clock 
Backup coin battery for reliable time readings even if main system loses power.
Temperature
Accurate sensor (adafruit probably)
Bonus points if it reads humidity!
Wifi Module
Module that uses a 2gb SIM card to create a small wifi signal
Passive module and only needs power to function
SD Card Reader
MicroSD card reader needs to be wired into the system to collect data
Processing
I’ve been prototyping with an arduino nano with wifi compatibility (we can switch to ESP32 board if anyone has any preference)
Power
Power stored in LiPo battery
Needs to be charged by solar panel, however system needs to be on and running constantly
If possible, we’d love to have a function that reads the voltage coming from the battery and solar panel, this is important info to be logged
For this project, we’ll need the most help with the power distribution 
Output
Fans
System uses 2 fans speed controlled using PWM
I created a system using two fans and an L293D chip that was effective in the desired function, however I am very open to change the system if there is a better way
Linear actuator
Electronic linear actuator, self explanatory
We've experimented with two types of actuators
Stepper motor and worm drive actuator
Not enough torque for desired function and programming stepper motors sucks
Servo-adjacent linear actuator
We also experimented with a linear actuator that functioned similar to a servo (taking inputs 1-180 to move to a specified position)
This was extremely powerful and worked well, however it requires an external power source and we could never get it to function across the entire range of values 1-180

#Software: 
General overview: System reads inputs wirelessly from user interface (a google sheet) and sets values in code based on this input. System then reads temp value and logs this to the spreadsheet and an onboard microSD. Depending on temperature, fan speed is adjusted. Fan speed logged to spreadsheet and MicroSD. Read real time clock sensor, if enough time has passed, send preset value to linear actuator. Message sent to Spreadsheet and SD with timestamp and current actuator position. Loop every 5 minutes.

Code: Everything Programed in C++, Arduino IDE
Libraries: Linear actuator, temp sensor, RTC, PWM library, SD Card, Wifi, http client

Values read wirelessly:
Max Temp
Time between Dosing
System Check
Compression value
Emergency shutoff

Values read onboard:
Temp value
Real time clock
Voltage?
