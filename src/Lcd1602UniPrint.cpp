#include <Lcd1602UniPrint.h>

int Lcd1602UniPrint::len(const char *s) {
  int len = 0;
  while (*s)
    len += (*s++ & 0xc0) != 0x80;
  return len;
}

void Lcd1602UniPrint::repeat(const char *ch, int n) {
  for (int i = 0; i < n; i++) {
    d.print(ch);
  }
}

void Lcd1602UniPrint::print_dec_lr(const char *label, int value, bool clean) {
  print_dec_right(label, value, 1, clean);
}

void Lcd1602UniPrint::print_dec_ur(const char *label, int value, bool clean) {
  print_dec_right(label, value, 0, clean);
}

void Lcd1602UniPrint::print_dec_ll(const char *label, int value, bool clean) {
  print_dec_left(label, value, 1, clean);
}

void Lcd1602UniPrint::print_dec_ul(const char *label, int value, bool clean) {
  print_dec_left(label, value, 0, clean);
}

void Lcd1602UniPrint::print_label_lr(const char *label, bool clean) {
  print_label_right(label, 1, clean);
}

void Lcd1602UniPrint::print_label_ur(const char *label, bool clean) {
  print_label_right(label, 0, clean);
}

void Lcd1602UniPrint::print_label_ll(const char *label, bool clean) {
  print_label_left(label, 1, clean);
}

void Lcd1602UniPrint::print_label_ul(const char *label, bool clean) {
  print_label_left(label, 0, clean);
}

void Lcd1602UniPrint::print_dec_left(const char *label, int value, int line,
                                     bool clean) {
  d.setCursor(0, line);
  d.print(label);
  d.print(value, DEC);
  if (clean) {
    repeat(" ", 16 - len(label) - String(value).length());
  }
}

void Lcd1602UniPrint::print_dec_right(const char *label, int value, int line,
                                      bool clean) {
  int space_count = 16 - len(label) - String(value).length();
  if (clean) {
    d.setCursor(0, line);
    repeat(" ", space_count);
  } else {
    d.setCursor(space_count, line);
  }
  d.print(label);
  d.print(value, DEC);
}

void Lcd1602UniPrint::print_label_left(const char *label, int line,
                                       bool clean) {
  d.setCursor(0, line);
  d.print(label);
  if (clean) {
    repeat(" ", 16 - len(label));
  }
}

void Lcd1602UniPrint::print_label_right(const char *label, int line,
                                        bool clean) {
  int space_count = 16 - len(label);
  if (clean) {
    d.setCursor(0, line);
    repeat(" ", space_count);
  } else {
    d.setCursor(space_count, line);
  }
  d.print(label);
}
