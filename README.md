# two_wheel

- for cheap robot kit

...future
- ROS
  - in:cmd_vel
  - out:odom

## howto

- Arduino UNO
- DG01D-E
  - [エンコーダ付きホビーメタルギアドモーター（DG01D-E） - スイッチサイエンス](https://www.switch-science.com/catalog/6374/)

## pin assign

  |Encoder|Arduino Uno|Note|
  |-|-|-|
  |0 A|2|attatchInterrupt|
  |0 B|4|digitalRead(anything is ok)|
  |1 A|3|attatchInterrupt|
  |1 B|5|digitalRead(anything is ok)|
