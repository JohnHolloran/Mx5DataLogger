#ifndef ClearScoresScreen_h
#define ClearScoresScreen_h

#include "Buttons.h"
#include "Screen.h"
#include "ClearScoresSuccessScreen.h"


class ClearScoresScreen : 
public Screen
{
private:
  Screen* successScreen;
  boolean lastAlternateMode;

public:
  ClearScoresScreen(Lcd* lcd, Screen* next) : 
  Screen(lcd),
  lastAlternateMode(false)
  {
    nextScreen = next;
    successScreen = new ClearScoresSuccessScreen(lcd);
    successScreen->SetNextScreen(nextScreen);
  }

  void Init()
  {
    lcd->GoBig();
    lcd->printLine(F("    Clear"));
    lcd->printLine(F("    High"));
    lcd->printLine(F("   Scores?"));

    if(Buttons::AlternateMode())
    {
      lcd->print(F("     No"));
      lastAlternateMode = true;
    }
    else
    {
      lcd->print(F("     Yes"));
      lastAlternateMode = false;
    }
  }

  void RefreshValues()
  {
    if(Buttons::AlternateMode() != lastAlternateMode)
    {
      lcd->ClearDisplay();
      Init();
    }
  }

  Screen* NextScreen()
  {
    if(Buttons::AlternateMode())
    {
      return nextScreen;
    }

    return successScreen;
  }
};

#endif

