# Image-Processing
Some Image Processing Algorithms implemented in cpp . 

## Operations supported 
-> Conversion to grayscale 

This readme will be updated  after some cleanup of code stay tuned

## Gray-Scale Conversion 

### Three methods have been employed for conversion into gray-scale images . 

Lets convert the following image to grayscale : 

![Spiderman strange](/assets/spiderman.jpg)

#### 1) Average method for Conversion 

In this method we take the average value of the pixel values R,G,B to get the gray-scale pixel . 

grayscale = R+G+B/3

The result we get is as follows : 

![Gray Spidey](/assets/Average_gray.png)

Which looks good wnough but is not perfect .


#### 2) Lightness Method for conversion

In this method we take the average value of the components with highest and lowest value . i.e.

grayscale          = {min(R,G,B) + max(R,G,B)} / 2
(pixel intensity)

The result we get with this method is as follows : 

![Light gray](/assets/Light_gray.png)


Which is not very accurate and actually seems to be the worst method till now. 


#### 3) Luminosity Method for conversion 

The best method is the luminosity method that successfully solves the problems of previous methods.

Based on the aforementioned observations, we should take a weighted average of the components. The contribution of blue to the final value should decrease, and the contribution of green should increase. After some experiments and more in-depth analysis, researchers have concluded in the equation below:

grayscale = (0.3 * R + 0.59 * G + 0.11 * B)/3

Here most weight is given to green colored pixels as humans are said to percieve green light well . 

![Luminous](/assets/Lum_gray.jpg)

This is the best method for grayscale inversion . 

## Flipping Images 

#### Flipping image along X axis ( Horizontal Flip)

![Horizontal Flip](/assets/Xflip.jpg)

The formula used for the flip is illustrated below 

![figure](/assets/flipeg.png)

Here we exchange the pixels marked with similar colour . The formula used to find similar pixels is given below. 

![formula](/assets/flipeg2.png)

###### Here x goes till w/2 and we find the pairs by substracting from the width .

#### Flip image over Y axis (vertical flip)


Similarly the same logic is used for vertical flip and we get the following result . Here y will go till h/2.

![Vertical](/assets/flipy.jpg)

