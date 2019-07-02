import processing.serial.*;
import ddf.minim.*;

Minim minim;
AudioPlayer player;

Serial port;

PImage moon;
PImage sun;
int numFrames = 5;
int frame = 0;
PImage[] images = new PImage[numFrames];

void setup() {
  size(600,600,P3D);
  noStroke();
  moon = loadImage("moon.jpg");
  sun = loadImage("sun.jpg");
  frameRate(5);
  images[0] = loadImage("sun01.jpg");
  images[1] = loadImage("sun02.jpg");
  images[2] = loadImage("sun03.jpg");
  images[3] = loadImage("sun04.jpg");
  images[4] = loadImage("sun05.jpg");
  
  port = new Serial(this,"COM4",9600); // com is same with arduino
  minim = new Minim(this);
  player = minim.loadFile("moon.mp3");
}

void draw() {
  
  while(port.available()>0){
    char input = port.readChar();
    
    switch(input){
      case'a':      
      image(sun,0,0);
      break;
      
      case'b':      
      background(sun);
      frame++;
      if (frame == numFrames){
        frame = 0;
      }
      image(images[frame],0,0);
      
      break;
      
      case'c':      
      image(moon,0,0);
      break;
      
      case'd':      
      image(moon,0,0);
      player.play();
      break;
      
      default:break;
    }
  }
}
