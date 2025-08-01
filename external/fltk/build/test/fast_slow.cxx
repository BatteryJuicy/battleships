// generated by Fast Light User Interface Designer (fluid) version 1.0403

#include "fast_slow.h"

Fl_Slider *control=(Fl_Slider *)0;

static void cb_control(Fl_Slider* o, void*) {
  fast->value(o->value());
  if (!Fl::pushed()) slow->value(o->value());
}

Fl_Slider *fast=(Fl_Slider *)0;

Fl_Slider *slow=(Fl_Slider *)0;

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(318, 443);
    w = o; (void)w;
    { Fl_Slider* o = control = new Fl_Slider(90, 200, 30, 200, "move\nthis");
      control->callback((Fl_Callback*)cb_control);
      o->when(FL_WHEN_CHANGED|FL_WHEN_RELEASE|FL_WHEN_NOT_CHANGED);
    } // Fl_Slider* control
    { Fl_Slider* o = fast = new Fl_Slider(140, 200, 30, 200, "fast\nredraw");
      o->set_output();
    } // Fl_Slider* fast
    { Fl_Slider* o = slow = new Fl_Slider(190, 200, 30, 200, "slow\nredraw");
      o->set_output();
    } // Fl_Slider* slow
    { Fl_Box* o = new Fl_Box(10, 10, 300, 180, "The left slider has changed( FL_WHEN_CHANGED | FL_WHEN_RELEASE | FL_WHEN_NOT_"
"CHANGED) so it produces a callback on both drag and release mouse events.\nThe"
" middle slider (representing a widget with low overhead) is changed on every m"
"ouse movement.\nThe right slider (representing a widget with high overhead) is"
" only updated when the mouse is released, by checking if Fl::pushed() is zero.");
      o->box(FL_DOWN_BOX);
      o->color((Fl_Color)53);
      o->selection_color(FL_DARK1);
      o->labelfont(4);
      o->labelsize(12);
      o->align(Fl_Align(132|FL_ALIGN_INSIDE));
    } // Fl_Box* o
    o->resizable(o);
    o->end();
  } // Fl_Double_Window* o
  w->show(argc, argv);
  return Fl::run();
}
