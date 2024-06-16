# CoreMP135_LCD_backlight_setting


![image](https://github.com/nnn112358/CoreMP135_LCD_backlight_setting/assets/27625496/310ec974-7242-4b90-bce0-5e204651ae7a)

CoreMP135のLCDバックライトの明るさはaxp2101のLDLO1から供給される電圧によって、設定することができます。<br>
CoreMP135のLCDはややまぶしいため、LCDバックライトを調整できるプログラムを作成しました。<br>
The brightness of the LCD backlight of the CoreMP135 can be set by the voltage supplied by the axp2101.<br>
The LCD on the CoreMP135 is somewhat glaring, so a program was created to adjust the LCD backlight.<br><br>

<img width="640" alt="image1" src="https://github.com/nnn112358/CoreMP135_LCD_backlight_setting/assets/27625496/777dfd4b-1087-4614-b609-0d0b7097ca45"><br>
CoreMP135のLCDバックライトはaxp2101のLDLO1と接続されており、LDLO1に設定する電圧によって、バックライトの明るさを設定することができます。<br>

<img width="640" alt="image2" src="https://github.com/nnn112358/CoreMP135_LCD_backlight_setting/assets/27625496/a386b683-f3ab-48c8-bf3c-dae81d94dece"><br>
<br>LDLO1は、レジスタのアドレスが0x99であり、レジスタに値を書き込むことで、100mVずつ設定することができます。

Cross Compile Enviroment
``` 
$ arm-linux-gnueabihf-g++ -o coremp135_i2c_backlight_ctrl coremp135_i2c_backlight_ctrl.cpp 
```

Run with CoreMP135
```
$ sudo ./coremp135_i2c_backlight_ctrl
Enter AXP2101 DLDO1 Setting integer: 22
AXP2101 DLDO1 Valtage: 2.7[V]
Dec: 22
Hex: 16
Bi: 00000000000000000000000000010110
Data written successfully.
```


# Reference
M5Stack CoreMP135のI2C/SPI内部配線まとめ (上級開発者向け)<br>
https://qiita.com/memetan/items/2c1ca1e34b06a2eaaeb8<br>
M5CoreMP135<br>
https://docs.m5stack.com/en/core/M5CoreMP135<br>
AXP2101<br>
https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/docs/products/core/Core2%20v1.1/axp2101.pdf<br>
