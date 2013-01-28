#ifndef HighScoreScreen_h
#define HighScoreScreen_h

#include "Buttons.h"
#include "ClearScoresScreen.h"
#include "Screen.h"

class HighScoreScreen : 
public Screen
{
private:
  Screen* clearScoresScreen;
public:
  HighScoreScreen(Lcd* lcd) : 
  Screen(lcd)
  {
    clearScoresScreen = new ClearScoresScreen(lcd, this);
  }

  void Init()
  {
    lcd->GoSmall();
    lcd->printLine("- High Scores Board-");
  }

  void RefreshValues()
  {
    static int test = 0;
    lcd->printSmallInt(test, 4, 5, 5);
    test++;
  }

  Screen* NextScreen()
  {
    if(Buttons::AlternateMode())
    {
      return clearScoresScreen;
    }

    return nextScreen;
  }
};

#endif

