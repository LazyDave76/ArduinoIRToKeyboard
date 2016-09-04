/*
 *    IR Remote Control to Keyboard Adapter by LazyDave76
 *    http://lazydave.net
 *    
 *    This does exactly what it says on the tin, it takes an IR Code
 *    from an IR Sensor Module and Presses Keys on the Keyboard.
 *    
 *    This sketch requires an Arduino Leonardo compatible board,
 *    It will NOT work with an Arduino UNO or Arduino UNO Clone boards.
 */


#include <IRremote.h> // https://github.com/z3t0/Arduino-IRremote/blob/master/IRremote.h
#include <Keyboard.h> // this is part of the Arduino IDE Libraries

int recvPin = 11;
IRrecv irrecv(recvPin);
decode_results  results;

void  setup ( )
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  Keyboard.begin();
}

void  loop ( )
{
  if (irrecv.decode(&results)) {

    Serial.print(" IR Received -->");
    Serial.println(results.value);

    sendKeyboard(results);
    irrecv.resume();
  }
}

void sendKeyboard(decode_results irCode) {

/*  
 *  You should modify the switch statement in this method if
 *  the default settings dont work.  
 *  
 *  Use SerialMonitor (Ctrl+Shift+M) to see the values that 
 *  your Remote Control sends on each key press and replace them.
 *  
 *  Full list of all the 'special keys' (FKeys, Cursors, etc.)
 *  https://www.arduino.cc/en/Reference/KeyboardModifiers
 *  
 *  For all other alpha-numeric keys, use ASCII values.
 *  http://www.asciitable.com/
 */
  
  switch (irCode.value) {
    case 551486205   : Keyboard.write(KEY_UP_ARROW);     break;
    case 551518845   : Keyboard.write(KEY_DOWN_ARROW);   break;
    case 551542815   : Keyboard.write(KEY_LEFT_ARROW);   break;
    case 551510175   : Keyboard.write(KEY_RIGHT_ARROW);  break;
    case 551494365   : Keyboard.write(KEY_RETURN);       break;
    case 551522415   : Keyboard.write(KEY_F8);           break;
    case 551490795   : Keyboard.write(KEY_BACKSPACE);    break;
    case 551502015   : Keyboard.write('+');              break;
    case 551534655   : Keyboard.write('-');              break;
    case 551507370   : Keyboard.write('i');              break;
    default:
      Serial.println("Unmapped key!");
  }
}
