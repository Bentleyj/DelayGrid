# DelayGrid

A simple Addon for making a really efficient delay grid. Uses a simple shader instead of the circular buffer.

Restrictions:
 - Can't control delay amount, each image is delayed exactly one frame and no more or less.

Wins:
 - Wicked fast, low overhead. Use this with optical flow by adding ofxSyphon to a second app maybe?

