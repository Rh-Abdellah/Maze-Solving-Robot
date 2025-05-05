# 🤖 Maze-Solving Robot

An autonomous robot that navigates and solves mazes using ultrasonic sensors and a PID controller for precise motion control.

![Uploading made-solver-robot.png…]()

---

## 🚀 Features

- Autonomous maze solving behavior
- Obstacle avoidance using 3 HC-SR04 ultrasonic sensors
- Dynamic motor control with PID for accurate navigation
- Powered by Arduino UNO and controlled with an L293D Motor Shield

---

## 🔧 Hardware Used

- Arduino UNO
- L293D Motor Driver Shield (Quad H-Bridge)
- 2x DC Motors + Wheels
- 3x HC-SR04 Ultrasonic Sensors
- 1x Caster Wheel
- 7.4V or 9V battery pack
- Jumper wires and chassis

---

## 🧠 How It Works

The robot continuously scans its surroundings:

- If the path is clear, it moves forward while using PID to correct its trajectory.
- If it detects an obstacle in front, it compares the left and right distances and turns toward the side with more space.
- The PID controller adjusts motor speeds based on the difference between left and right distances to stay centered in a corridor.

---

## 🧪 PID Control Logic

The robot uses a PID controller with:

- **P** for quick reaction to side error
- **D** for smoothing
- **I** (optional) for long-term drift correction

```cpp
// Example PID formula
correction = kp * error + ki * integral + kd * derivative;
```

---

## 📷 Media

### Wiring Diagram  
![Wiring Diagram](images/wiring_diagram.png)

### Robot Photo  
![Robot](images/robot_front_view.jpg)

### Demo Video  
📽️ [Click to watch](videos/demo.mp4)

---

## 💻 Code

All Arduino code is in the [`Arduino_Code`](Arduino_Code) folder:  
👉 [MazeSolvingRobot.ino](Arduino_Code/MazeSolvingRobot.ino)

---

## 🧭 Future Improvements

- Implement maze-solving algorithms (e.g. Wall Following, Tremaux)
- Add wheel encoders for precision
- Save the maze map using EEPROM

---

## 🛠️ Setup Instructions

1. Wire up the sensors and motors as described.
2. Upload the code to your Arduino UNO.
3. Place the robot at the maze entrance and power it up.

---

## 📄 License

This project is open source under the MIT License.

---

## 🙌 Acknowledgments

Thanks to the Arduino community and open-source developers.
