void SolarisMIDI() {
    switch (command) {

    /////////////////////////////// MIDI ///////////////////////////////
/*
    // OFF
    case 12:
      OnOff(false);
      break;

    // ON
    case 13:
      OnOff(true);
      break;

    // Strobe
    case 14:
      Strobe(interval, true);
      break;

    // Cross-Fade
    case 15:
      CrossFade(sinInterval, true);
      break;

    // Breathe
    case 16:
      Breathe(breatheint1, breatheint2);
      break;

    // Single Breathe
    case 17:
      BreatheSingle(breatheint1, breatheint2);
      break;

    // Parameter-based Breathe
    case 18:
      BreatheSingle(breatheint1, 40 * parameter);
      break;

    // Strobe (parameter-based)
    case 19:
      Strobe(parameter, true);
      break;

    // FadeOut (parameter-based)
    case 20:
      FadeParameter(255, 0, 40 * parameter);
      break;

    // FadeIn (parameter-based)
    case 21:
      FadeParameter(0, 255, 40 * parameter);
      break;

    // Cross-Fade (parameter-based)
    case 22:
      CrossFade(40 * parameter, true);
      break;

    // Complicated Breathe (parameter-based)
    case 23:
      BreatheHard(breatheint1, constant_commands[0]);
      break;

    // Fade in Strobe (parameter-based)
    case 24:
      FadeToStrobe(100 * parameter, constant_commands[0] * 10);
      break;

    // Fade in Cross-Fade
    case 25:
      VariableCrossFade(50 * parameter, constant_commands[0]);
      break;

    // Brightness (parameter-based)
    case 26:
      {
        byte b = map(parameter, 1, 127, 0, 255);
        Brightness(b);
        break;
      }

    // Fade 0 to 32 (parameter-based)
    case 27:
      FadeParameter(0, 32, 40 * parameter);
      break;

    // Fade 255 to 32 (parameter-based)
    case 28:
      FadeParameter(255, 32, 40 * parameter);
      break;

    // Fade 32 to 0 (parameter-based)
    case 29:
      FadeParameter(32, 0, 40 * parameter);
      break;

    // Fade 32 to 255 (parameter-based)
    case 30:
      FadeParameter(32, 255, 40 * parameter);
      break;

    case 31:
      FadeParameter(4 * (parameter - 48), 1, 250);
      break;

    // Fade 32 to 0 (parameter-based)
    case 32:
      FadeParameter(6, 0, 40 * parameter);
      break;

    case 40:
      analogWrite(HANDS_PWM_PIN, parameter * 2);
      break;

    default:
      Strobe(interval, true);
      break;
  }

  inner.show();
  middle.show();
  outer.show();
  */
}