# MY EXPERIMENT

## HOW LIGHT INTERACTS WITH A SURFACE IN A 3D WORLD

---

## PART 1: THE PHYSICAL EXPERIMENT

Okay, so I did a little bit of experiment with things around me physically, now I get to paint the picture for you so you can follow along. So here is what I have.

### The Setup

So, take for instance, my room is like a square. And then on the far left side of the room, I'm standing holding a flashlight. So, the flashlight is my light source and then me, I'm holding the flashlight but I'm on the far left side of the room.

And on the far right side of the room is a chair and on top of the chair is a mini fan, which is my object. So, the object is my mini fan and the chair is my surface. So, that's on the far right side of the room.

*A picture representation to support your imagination*

```
┌─────────────────────────────────────────────────────────────────────────┐
│                              MY ROOM                                    │
│                                                                         │
│                                                                         │
│    🧍🔦                                                    🪑🌀       │
│    ME                                                    CHAIR          │
│    (holding                                              (with          │
│    flashlight)                                           mini fan       │
│                                                          on top)        │
│                                                                         │
│    FAR LEFT                                              FAR RIGHT      │
│    SIDE                                                  SIDE           │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### What I Observed

When I put on the flashlight and it comes on, I shine it directly to the surface of the chair, which is where my mini fan is at. And this is located on the far right side of the room. The light beam is coming from the far left.



```
    🔦 ═══════════════════════════════════════════════════════════▶ 🌀
    
    ME                        LIGHT BEAM                         FAN
    (far left)                                               (far right)
```

**Observation 1: Direct Light = Brighter Surface**

Now, the surface looks brighter when the light hits directly on the fan but it's dimmer at the sides of the chair, the four legs of the chair and under the chair looks dimmer than the surface, which is where the fan is.



```
                                                         BRIGHT!
                                                           ↓
    🔦 ══════════════════════════════════════════════════▶ 🌀 ← fan surface
                                                          ┃┃
                                                          ┃┃ ← legs (dim)
                                                          ┃┃
                                                    ▒▒▒▒▒▒▒▒▒▒ ← under chair
                                                       (dimmer)
```

**Observation 2: Stable Light Source = Stable Brightness**

Now, if the light source position is stable, if I do not shift my hand, I'm stable, it doesn't affect the surface.



```
    STABLE HAND:
    
    🔦 ══════════════════════════════════════════════════▶ 🌀
    (not moving)                                         (bright!)
```

**Observation 3: Shifting Light Source = Dimmer Surface**

But as soon as I shift my hand away or my hand begins to slant, the brightness on the surface is affected and then it causes the reflection of light on the fan to reduce drastically or to become dimmer.


```
    HAND SLANTING:
    
    🔦
      ╲
        ╲
          ╲══════════════════════════════════════════════▶ 
                                                          🌀
                                                       (dimmer!)
```

**Observation 4: Object in Between = Shadow Forms**

Now, if an object comes in between the flashlight I'm shining and the surface, which is where the fan is at. if an object does comes in between the beams (the rays of light), then a shadow begins to form.



```
    OBJECT BLOCKING LIGHT:
    
    🔦 ════════════▶ 📦 ┃┃┃┃┃┃┃┃┃┃┃┃┃┃┃┃▶ 🌀
                    ↑              ↑
                 OBJECT         SHADOW
               (blocking)      (forms here)
```

### Summary of My Experiment

So, this is the experiment I performed. I'm on the far left, the chair and the fan is on the far right and then beams of light hit the fan.

---

## PART 2: TURNING MY EXPERIMENT INTO CODE

Now, how do I take what I observed and turn it into something a computer can understand? I need to use coordinates and math!

### Why Three Coordinates (x, y, z)?

Because my room exists in 3D space! I can move in three directions:



```
         UP (y)
          |
          |
          |
          +---------- RIGHT (x)
         /
        /
       /
    FORWARD (z)
```

The three coordinates represent:

- **x** = left/right
- **y** = up/down
- **z** = forward/backward

### Why is My Position (0, 0, 0)?

I'm the one holding the flashlight, so I make myself the starting point. Everything else I measure from where I'm standing.



```
    ME (holding flashlight)
           ↓
        (0,0,0)  ─────── measuring from here ───────▶  (65,0,0)
     "I call this                                     "The fan is 65
      position zero"                                   units from me"
```

### Why is the Fan at (65, 0, 0)?

Because the fan is 65 units to my RIGHT. It's not above me or below me (y = 0). It's not in front of me or behind me (z = 0). It's only to my right (x = 65).



```
    TOP-DOWN VIEW OF MY ROOM:

    +------------------------------------------+
    |                                          |
    |                                          |
    |  ME                               FAN    |
    |  🔦 -------------------------------- 🌀 |
    | (0,0,0)                         (65,0,0) |
    |                                          |
    |                                          |
    +------------------------------------------+
    
    ←―――――――――― x-axis (left to right) ―――――――――→
```

---

## PART 3: THE COMPLETE LIGHTING CALCULATION

Now let me walk through step by step how the computer calculates the brightness on my fan.



```
╔═══════════════════════════════════════════════════════════════════════════════╗
║                         COMPLETE LIGHTING CALCULATION                         ║
╚═══════════════════════════════════════════════════════════════════════════════╝
```

### STEP 1: DEFINE POSITIONS (Where is everything?)

First, we tell the computer where everything is in my room.

C

```
#define FLASHLIGHT_POSITION_X 0.0
#define FLASHLIGHT_POSITION_Y 0.0
#define FLASHLIGHT_POSITION_Z 0.0

#define FAN_POSITION_X 65.0
#define FAN_POSITION_Y 0.0
#define FAN_POSITION_Z 0.0
```

**Picture:**



```
    🔦                                                                    🌀
    Flashlight                                                           Fan
    (0, 0, 0)                                                        (65, 0, 0)
    
    "Flashlight is at starting point (where I'm standing)"
    "Fan is 65 units to the right"
```

---

### STEP 2: FIND DIRECTION (Which way does light travel?)

Now the computer needs to figure out: "Which way does the light go to get from me to the fan?"

C

```
double direction_x = FAN_POSITION_X - FLASHLIGHT_POSITION_X;
double direction_y = FAN_POSITION_Y - FLASHLIGHT_POSITION_Y;
double direction_z = FAN_POSITION_Z - FLASHLIGHT_POSITION_Z;
```

**The Math:**


```
direction_x = 65.0 - 0.0 = 65.0
direction_y = 0.0 - 0.0 = 0.0
direction_z = 0.0 - 0.0 = 0.0

Result: direction = (65, 0, 0)
```

**Picture:**



```
    🔦 ─────────────────────────────────────────────────────────────────→ 🌀
                              65 units this way
    
    "To get from flashlight to fan: go 65 right, 0 up, 0 forward"
```

**What does "double" mean here?**

"double" is NOT about direction. It's the TYPE of number! It tells the computer "this will be a decimal number" like 65.0 or 3.14159 instead of just whole numbers like 65 or 3.

---

### STEP 3: CALCULATE DISTANCE (How far is the fan?)

Now we need to know: "How far away is the fan from me?"

C

```
double length = sqrt(direction_x * direction_x + 
                     direction_y * direction_y + 
                     direction_z * direction_z);
```

**The Math:**


```
direction_x * direction_x = 65 × 65 = 4225
direction_y * direction_y = 0 × 0 = 0
direction_z * direction_z = 0 × 0 = 0

Add them: 4225 + 0 + 0 = 4225

sqrt(4225) = 65

length = 65
```

**Why multiply by itself first?**

Because of the Pythagorean theorem! Like in school:


```
    For a right triangle:

           /|
          / |
       c /  | b
        /   |
       /____|
          a

    c² = a² + b²
    c = sqrt(a² + b²)
```

**Picture:**


```
    🔦 ←───────────── 65 units ─────────────→ 🌀
    
    "The fan is 65 units away from the flashlight"
```

---

### STEP 4: NORMALIZE DIRECTION (Remove distance, keep only direction)

Now here's an important step. I want to know ONLY the direction, not the distance. So I "normalize" it.

C

```
direction_x /= length;   // Same as: direction_x = direction_x / length
direction_y /= length;
direction_z /= length;
```

**The Math:**


```
direction_x = 65 / 65 = 1.0
direction_y = 0 / 65 = 0.0
direction_z = 0 / 65 = 0.0

Result: normalized direction = (1, 0, 0)
```

**What's the difference?**


```
Before: (65, 0, 0) = "Go 65 units right"     ← includes distance
After:  (1, 0, 0)  = "Go right"              ← pure direction only
```

**Picture:**


```
    🔦 →  (just pointing right, no distance info)
    
    "Light is traveling in the RIGHT direction"
```

**Why does direction always become 1?**

Because "1" means "100% in this direction." It's like saying:


```
"I'm walking 100% to the right, 0% up, 0% forward"

This becomes: (1, 0, 0)
              ↑  ↑  ↑
            100% 0% 0%
```

---

### STEP 5: DEFINE SURFACE NORMAL (Which way is the fan facing?)

This is important! Remember in my experiment, when I shift my hand, the brightness changes? Same thing happens if the FAN is facing a different direction.

The "surface normal" is which way the surface is pointing.

C

```
double surface_normal_x = 1.0;
double surface_normal_y = 0.0;
double surface_normal_z = 0.0;
```

**Result:** surface normal = (1, 0, 0)

**Picture:**


```
                                                                ← 🌀
                                                          Fan facing LEFT
                                                       (toward flashlight)
    
    "The fan surface is facing left (toward the flashlight)"
```

**What if the fan is lying down? Facing up?**


```
Fan facing flashlight (standing up):

    🔦 ───────────────────────────────────────────▶ 🌀
                                                   ↑
                                            surface normal = (1,0,0)
                                            Light hits DIRECTLY!
                                            BRIGHT!


Fan facing UP (lying down):

                                                   ↑ surface normal = (0,1,0)
    🔦 ───────────────────────────────────────────▶ 🌀
                                                   
                                            Light just grazes past!
                                            DIM!
```

---

### STEP 6: DOT PRODUCT (How directly does light hit the surface?)

Now the computer calculates: "How directly does the light hit the fan?"

This is where the angle matters. Remember in my experiment, when I slant my hand, the light becomes dimmer? This step calculates that.

C

```
double dot_product = direction_x * surface_normal_x + 
                     direction_y * surface_normal_y + 
                     direction_z * surface_normal_z;
```

**The Math:**



```
dot_product = 1×1 + 0×0 + 0×0
dot_product = 1

Result: dot_product = 1.0 (perfect direct hit!)
```

**Picture:**



```
Light direction: →
Surface facing:  ←
                 
They point at each other = DIRECT HIT = dot product = 1
```

**What the dot product means:**



```
dot_product = 1.0  →  "Light hits perfectly straight on"   (BRIGHT!)
dot_product = 0.5  →  "Light hits at an angle"             (DIMMER)
dot_product = 0.0  →  "Light misses (parallel to surface)" (NO LIGHT)
```

---

### STEP 7: DISTANCE FACTOR (How much does distance weaken the light?)


In my experiment, when I move the fan further away, it gets dimmer. This is called the "Inverse Square Law."

C

```
double distance_factor = 1.0 / (distance * distance);
```

**The Math:**


```
distance_factor = 1.0 / (65 × 65)
distance_factor = 1.0 / 4225
distance_factor = 0.00024

Result: distance_factor = 0.00024
```

**What does this mean?**


```
"At 65 units away, light is only 0.024% as strong!"
```

**Picture:**


```
Close (distance=1):   🔦)) ▪️     Light concentrated = STRONG
Far (distance=65):    🔦)))))))))))))))))))) ▪️   Light spread = WEAK
```

**Why does distance matter so much?**

Because light SPREADS OUT as it travels!


```
CLOSE TO FLASHLIGHT:
Light covers small area = CONCENTRATED = BRIGHT

     🔦))
        ▪️  ← Small area, lots of light


FAR FROM FLASHLIGHT:
Light covers BIG area = SPREAD OUT = DIM

     🔦)))))))))))))))
                   ▪️  ← Same light spread over big area
```

**The Inverse Square Law:**

```
Distance = 1    →  Brightness = 1 / (1 × 1) = 1/1   = 1.0
Distance = 2    →  Brightness = 1 / (2 × 2) = 1/4   = 0.25
Distance = 3    →  Brightness = 1 / (3 × 3) = 1/9   = 0.11
Distance = 10   →  Brightness = 1 / (10 × 10) = 1/100 = 0.01
Distance = 65   →  Brightness = 1 / (65 × 65) = 1/4225 = 0.00024

Double the distance = ONE QUARTER the brightness!
```

---

### STEP 8: FINAL BRIGHTNESS (Put it all together!)

Now we combine everything to get the final brightness on my fan.

C

```
double brightness = LIGHT_INTENSITY * fmax(dot_product, 0.0) * distance_factor;
```

**The Math:**


```
brightness = 1.0 × 1.0 × 0.00024
brightness = 0.00024
```

**The Formula Explained:**


```
┌─────────────────────────────────────────────────────────────────────┐
│                                                                     │
│  BRIGHTNESS = LIGHT_INTENSITY × DOT_PRODUCT × DISTANCE_FACTOR       │
│                                                                     │
│       ↓              ↓              ↓              ↓                │
│                                                                     │
│  "Final      "How strong   "How directly  "How much does            │
│   brightness   is the        does light     distance                │
│   on fan"      flashlight?"  hit?"          weaken it?"             │
│                                                                     │
│       ↓              ↓              ↓              ↓                │
│                                                                     │
│   0.00024    =    1.0       ×     1.0      ×    0.00024             │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

---

### FINAL RESULT


```
Brightness on the fan = 0.00024

Interpretation:
"The fan receives 0.024% of the original light intensity"
"Because it's far away (65 units), even though light hits directly!"
```


```
╔═══════════════════════════════════════════════════════════════════════════════╗
║                                    END                                        ║
╚═══════════════════════════════════════════════════════════════════════════════╝
```

---


**Output from running my code:**


```
Distance to fan: 65.000000
Dot product: 1.000000
Distance factor: 0.000237
Final brightness: 0.000237
```

---

## PART 4: WHY FLOATING POINT MATTERS

So, using floating point types like `float` or `double` in my code, I'm telling the computer to store numbers with a decimal component, which allows for much finer precision. This is what ensures that the positions, distances, and angles are represented as accurately as possible.

**Where floating point shows up in my experiment:**

|What We're Calculating|Example Value|Why Decimals Matter|
|---|---|---|
|Positions|65.0, 0.0|Could be 65.5 or 65.123|
|Distance|65.0|Could be 65.192...|
|Normalized direction|1.0, 0.707...|Often not whole numbers|
|Dot product|0.0 to 1.0|Usually decimals like 0.5, 0.707|
|Distance factor|0.00024|Very small decimal!|
|Final brightness|0.00024|Very small decimal!|


Without floating point (decimals), the computer would round these to 0 or 1, and all my calculations would be WRONG!

---

## PART 5: MY SUMMARY

### The Three Things That Affect Brightness


```
┌─────────────────────────────────────────────────────────────┐
│                                                             │
│   BRIGHTNESS depends on THREE things:                       │
│                                                             │
│   1. LIGHT_INTENSITY    → How strong is the flashlight?     │
│                                                             │
│   2. DOT_PRODUCT        → How directly does light hit?      │
│                            (angle between light & surface)  │
│                                                             │
│   3. DISTANCE_FACTOR    → How far away is the object?       │
│                            (further = dimmer)               │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Linking Back to My Physical Experiment

|What I Observed|What the Code Calculates|
|---|---|
|"I'm on the far left"|FLASHLIGHT_POSITION = (0, 0, 0)|
|"Fan is on the far right"|FAN_POSITION = (65, 0, 0)|
|"Light shines directly at fan"|direction = (1, 0, 0)|
|"Surface is brighter when light hits directly"|dot_product = 1.0 (direct hit)|
|"When I slant my hand, it gets dimmer"|dot_product < 1.0 (angled hit)|
|"Further away = dimmer"|distance_factor = 1/(distance²)|
|"Shadow forms when object blocks light"|(not in this code, but would attempt it soon!)|

---



So this is my experiment, from shining a flashlight in my room to writing actual code that calculates how bright my fan would be. And now I understand why we need floating point numbers, because all these calculations involve decimals, and without decimals, the computer can't represent reality accurately!