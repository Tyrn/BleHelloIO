#ifndef _LCD1602UNIPRINT_H
#define _LCD1602UNIPRINT_H

// Display mode: 1 - I2C; 2 - 10-pin.
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>

class Lcd1602UniPrint {
public:
  Lcd1602UniPrint(uint8_t lcd_Addr = 0x27, uint8_t lcd_cols = 16,
                  uint8_t lcd_rows = 2)
      : d(lcd_Addr, lcd_cols, lcd_rows) {}

  // Returns the length of a Unicode string in characters.
  static int len(const char *s);

  // Prints a character n times.
  void repeat(const char *ch, int n);

  // Prints a signed decimal number in the left corner.
  void print_dec_left(const char *label, int value, int line,
                      bool clean = true);

  // Prints a signed decimal number in the right corner.
  void print_dec_right(const char *label, int value, int line,
                       bool clean = true);

  // Prints a label in the left corner.
  void print_label_left(const char *label, int line, bool clean = true);

  // Prints a label in the right corner.
  void print_label_right(const char *label, int line, bool clean = true);

  // Prints a signed decimal number in the lower right corner.
  void print_dec_lr(const char *label, int value, bool clean = true);

  // Prints a signed decimal number in the upper right corner.
  void print_dec_ur(const char *label, int value, bool clean = true);

  // Prints a signed decimal number in the lower left corner.
  void print_dec_ll(const char *label, int value, bool clean = true);

  // Prints a signed decimal number in the upper left corner.
  void print_dec_ul(const char *label, int value, bool clean = true);

  // Prints a label in the lower right corner.
  void print_label_lr(const char *label, bool clean = true);

  // Prints a label in the upper right corner.
  void print_label_ur(const char *label, bool clean = true);

  // Prints a label in the lower left corner.
  void print_label_ll(const char *label, bool clean = true);

  // Prints a label in the upper left corner.
  void print_label_ul(const char *label, bool clean = true);

  LCD_1602_RUS d;

private:
};

#endif
