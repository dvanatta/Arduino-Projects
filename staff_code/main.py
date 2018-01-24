# CircuitPlaygroundExpress_NeoPixel
import board
import neopixel
import time

pixels = neopixel.NeoPixel(board.D1, 7, brightness=.5)
pixels.fill((0, 0, 0))
pixels.show()

# choose which demos to play
# 1 means play, 0 means don't!
simpleCircleDemo = 0
flashDemo = 0
rainbowDemo = 0
rainbowCycleDemo = 0
fire_flag = 1
ice_flag = 0

# RED = 0x100000  # (0x10, 0, 0) also works
RED = (255, 0, 0)
YELLOW = (255, 100, 0)
GREEN = (0, 0x10, 0)
AQUA = (0, 0x10, 0x10)
BLUE = (0, 0, 255)
PURPLE = (0x10, 0, 0x10)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)


def red_wheel(pos):
    # Input a value 0 to 255 to get a color value.
    # The colours are a transition r - g - b - back to r.
    return (10 * int(pos) + 200, 0, 0)


def wheel(pos):
    # Input a value 0 to 255 to get a color value.
    # The colours are a transition r - g - b - back to r.
    if pos < 85:
        return (int(pos * 3), int(255 - (pos * 3)), 0)
    elif pos < 170:
        pos -= 85
        return (int(255 - (pos * 3)), 0, int(pos * 3))
    else:
        pos -= 170
        return (0, int(pos * 3), int(255 - pos * 3))


def rainbow_cycle(wait):
    for j in range(255):
        for i in range(len(pixels)):
            idx = int((i * 256 / len(pixels)) + j * 10)
            pixels[i] = wheel(idx & 255)
        pixels.show()
        time.sleep(wait)


def ice():
    pixels.fill(BLUE)
    pixels[0] = WHITE
    pixels.show()


def fire(min_light=50, max_light=250, yellow=100):
    for j in range(min_light, max_light):
        pixels[2:7] = [(j, max(j-200, 0), 0), 0)] * 5
        pixels.show()
    # time.sleep(wait)
    for j in range(0, max_light - min_light):
        pixels[2:7] = [(250 - j, max(j-50, 0), 0)] * 5
        pixels.show()


# time.sleep(wait)


def rainbow(wait):
    for j in range(255):
        for i in range(0, len(pixels)):
            idx = int(i + j)
            pixels[i] = red_wheel(idx & 255)
        pixels.show()
        time.sleep(wait)


def singleColor(color):
    for i in range(len(pixels)):
        pixels[i] = color
    # time.sleep(1)
    time.sleep(1)


def simpleCircle(wait):
    for i in range(len(pixels)):
        pixels[i] = RED
        time.sleep(wait)
    time.sleep(1)
    for i in range(len(pixels)):
        pixels[i] = YELLOW
        time.sleep(wait)
    time.sleep(1)

    for i in range(len(pixels)):
        pixels[i] = GREEN
        time.sleep(wait)
    time.sleep(1)

    for i in range(len(pixels)):
        pixels[i] = AQUA
        time.sleep(wait)
    time.sleep(1)

    for i in range(len(pixels)):
        pixels[i] = BLUE
        time.sleep(wait)
    time.sleep(1)

    for i in range(len(pixels)):
        pixels[i] = PURPLE
        time.sleep(wait)
    time.sleep(1)

    for i in range(len(pixels)):
        pixels[i] = BLACK
        time.sleep(wait)
    time.sleep(1)

while True:
    #    pixels[1] = RED
    # pixels[0:7]= [RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW]

    #    pixels.show()
    #    continue
    if simpleCircleDemo:
        print('Simple Circle Demo')
        simpleCircle(.05)

    if flashDemo:  # this will play if flashDemo = 1 up above
        print('Flash Demo')
        pixels.fill((255, 0, 0))
        pixels.show()
        time.sleep(.25)

        pixels.fill((0, 255, 0))
        pixels.show()
        time.sleep(.25)

        pixels.fill((0, 0, 255))
        pixels.show()
        time.sleep(.25)

        pixels.fill((255, 255, 255))
        pixels.show()
        time.sleep(.25)

    if rainbowDemo:
        print('Rainbow Demo')
        rainbow(.000001)

    if fire_flag:
        pixels[0:2] = [RED, RED]
        fire(0)
    if ice_flag:
        ice()

    if rainbowCycleDemo:
        print('Rainbow Cycle Demo')
        rainbow_cycle(.001)
