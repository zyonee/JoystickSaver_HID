
   uint8_t Joy;
   uint8_t MemoJoy1 ;
   uint8_t MemoJoy2 ;

   void setup() {

     // Joystick 1
     // configure as DigIn  with pull up
     pinMode(9, INPUT_PULLUP);  //
     pinMode(8, INPUT_PULLUP);
     pinMode(7, INPUT_PULLUP);
     pinMode(6, INPUT_PULLUP);
     pinMode(5, INPUT_PULLUP);
     pinMode(4, INPUT_PULLUP);
    
//     // Joystick 2
//     pinMode(10, INPUT_PULLUP);
//     pinMode(16, INPUT_PULLUP);
//     pinMode(14, INPUT_PULLUP);
//     pinMode(15, INPUT_PULLUP);
//     pinMode(A0, INPUT_PULLUP);
//     pinMode(A1, INPUT_PULLUP);

   }

   void loop()
   {         // Joystick 1
         Joy = ~PIND & 0b10011111;     // read Port D, invert logic, mask relevant bits
         if (Joy != MemoJoy1) {        // state changed?
           HID_SendReport(3, &Joy, 1); // send HID report
           MemoJoy1 = Joy;             // save last state
         }
        // Joystick 2
         Joy = ~PIND & 0b11110011;
         if (Joy != MemoJoy2) {
           HID_SendReport(4, &Joy, 1);
           MemoJoy2 = Joy;
         } 
      }
