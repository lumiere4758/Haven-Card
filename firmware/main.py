from machine import Pin, SPI
import ssd1306

# initialise spi
spi = SPI(1, baudrate=10000000, polarity=0, phase=0, sck=Pin(4), mosi=Pin(5))

#initialise control pins
dc = Pin(2, Pin.OUT)
res = Pin(3, Pin.OUT)
cs = Pin(6, Pin.OUT)

#initialise oled display
display = ssd1306.SSD1306_SPI(128,64,spi,dc,res,cs)

#write welcome for starters

display.fill(0)
display.text("WELCOME",0,0,1)
display.show()