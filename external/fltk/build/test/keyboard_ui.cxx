// generated by Fast Light User Interface Designer (fluid) version 1.0403

#include "keyboard_ui.h"

MyWindow *my_window=(MyWindow *)0;

Fl_Output *key_output=(Fl_Output *)0;

Fl_Output *text_output=(Fl_Output *)0;

Fl_Dial *roller_x=(Fl_Dial *)0;

Fl_Dial *roller_y=(Fl_Dial *)0;

MyWindow* make_window() {
  { my_window = new MyWindow(495, 215);
    my_window->box(FL_FLAT_BOX);
    my_window->color(FL_BACKGROUND_COLOR);
    my_window->selection_color(FL_BACKGROUND_COLOR);
    my_window->labeltype(FL_NO_LABEL);
    my_window->labelfont(0);
    my_window->labelsize(14);
    my_window->labelcolor(FL_FOREGROUND_COLOR);
    my_window->align(Fl_Align(FL_ALIGN_TOP));
    my_window->when(FL_WHEN_RELEASE);
    { key_output = new Fl_Output(15, 20, 170, 30, "Fl::event_key():");
      key_output->labelsize(9);
      key_output->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Output* key_output
    { text_output = new Fl_Output(195, 20, 190, 30, "Fl::event_text():");
      text_output->labelsize(9);
      text_output->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Output* text_output
    { Fl_Button* o = new Fl_Button(15, 70, 20, 20, "Esc ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Escape));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(50, 70, 20, 20, "F1");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+1));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(70, 70, 20, 20, "F2");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+2));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(90, 70, 20, 20, "F3");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+3));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(110, 70, 20, 20, "F4");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+4));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 70, 20, 20, "F5");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+5));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(160, 70, 20, 20, "F6");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+6));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(180, 70, 20, 20, "F7");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+7));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(200, 70, 20, 20, "F8");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+8));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(230, 70, 20, 20, "F9");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+9));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(250, 70, 20, 20, "F10");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+10));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 70, 20, 20, "F11");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+11));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(290, 70, 20, 20, "F12");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+12));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(325, 70, 20, 20, "Print ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Print));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(345, 70, 20, 20, "Sclk ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Scroll_Lock));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(365, 70, 20, 20, "Paus ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Pause));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 70, 20, 20, "Help");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Help));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 70, 20, 20, "=");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'='));
    } // Fl_Button* o
    { roller_x = new Fl_Dial(440, 70, 20, 20, "x:");
      roller_x->box(FL_ROUND_UP_BOX);
      roller_x->selection_color(FL_BACKGROUND_COLOR);
      roller_x->labelsize(9);
      roller_x->step(0.1);
      roller_x->callback((Fl_Callback*)wheel_cb);
      roller_x->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Dial* roller_x
    { roller_y = new Fl_Dial(460, 70, 20, 20, "y:");
      roller_y->box(FL_ROUND_UP_BOX);
      roller_y->selection_color(FL_BACKGROUND_COLOR);
      roller_y->labelsize(9);
      roller_y->step(0.1);
      roller_y->callback((Fl_Callback*)wheel_cb);
      roller_y->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Dial* roller_y
    { Fl_Button* o = new Fl_Button(15, 100, 20, 20, "`");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(35, 100, 20, 20, "1");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(55, 100, 20, 20, "2");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(75, 100, 20, 20, "3");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(95, 100, 20, 20, "4");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(115, 100, 20, 20, "5");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(135, 100, 20, 20, "6");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(155, 100, 20, 20, "7");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(175, 100, 20, 20, "8");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(195, 100, 20, 20, "9");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(215, 100, 20, 20, "0");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(235, 100, 20, 20, "-");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(255, 100, 20, 20, "=");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(275, 100, 35, 20, "Bksp");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_BackSpace));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(325, 100, 20, 20, "Ins ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Insert));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(345, 100, 20, 20, "Home");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Home));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(365, 100, 20, 20, "pgup ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Page_Up));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 100, 20, 20, "Num");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Num_Lock));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 100, 20, 20, "/");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'/'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 100, 20, 20, "*");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'*'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(460, 100, 20, 20, "-");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'-'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(15, 120, 27, 20, "Tab");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Tab));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(42, 120, 20, 20, "Q");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(62, 120, 20, 20, "W");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(82, 120, 20, 20, "E");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(102, 120, 20, 20, "R");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(122, 120, 20, 20, "T");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(142, 120, 20, 20, "Y");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(162, 120, 20, 20, "U");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(182, 120, 20, 20, "I");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(202, 120, 20, 20, "O");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(222, 120, 20, 20, "P");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(242, 120, 20, 20, "[");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(262, 120, 20, 20, "]");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(282, 120, 28, 20, "\\");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(325, 120, 20, 20, "Del ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Delete));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(345, 120, 20, 20, "End ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_End));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(365, 120, 20, 20, "pgdn ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Page_Down));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 120, 20, 20, "7");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'7'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 120, 20, 20, "8");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'8'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 120, 20, 20, "9");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'9'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(460, 120, 20, 40, "+");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'+'));
      o->align(Fl_Align(FL_ALIGN_TOP|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(15, 140, 36, 20, "Lock");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Caps_Lock));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(51, 140, 20, 20, "A");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(71, 140, 20, 20, "S");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(91, 140, 20, 20, "D");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(111, 140, 20, 20, "F");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(131, 140, 20, 20, "G");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(151, 140, 20, 20, "H");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(171, 140, 20, 20, "J");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(191, 140, 20, 20, "K");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(211, 140, 20, 20, "L");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(231, 140, 20, 20, ";");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(251, 140, 20, 20, "\'");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(271, 140, 39, 20, "Enter");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Enter));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 140, 20, 20, "4");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'4'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 140, 20, 20, "5");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'5'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 140, 20, 20, "6");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'6'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(15, 160, 45, 20, "Shift");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Shift_L));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(60, 160, 20, 20, "Z");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(80, 160, 20, 20, "X");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(100, 160, 20, 20, "C");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(120, 160, 20, 20, "V");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 160, 20, 20, "B");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(160, 160, 20, 20, "N");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(180, 160, 20, 20, "M");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(200, 160, 20, 20, ",");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(220, 160, 20, 20, ".");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(240, 160, 20, 20, "/");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(260, 160, 50, 20, "Shift");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Shift_R));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(345, 160, 20, 20, "@8->");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(10);
      o->labelcolor(FL_DARK1);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Up));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 160, 20, 20, "1");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'1'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 160, 20, 20, "2");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'2'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 160, 20, 20, "3");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'3'));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(460, 160, 20, 40);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP_Enter));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(15, 180, 30, 20, "Ctrl");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Control_L));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(45, 180, 30, 20, "Meta ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Meta_L));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(75, 180, 30, 20, "Alt ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Alt_L));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(105, 180, 85, 20);
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(' '));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(190, 180, 30, 20, "Alt ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Alt_R));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(220, 180, 30, 20, "Meta ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Meta_R));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(250, 180, 30, 20, "Menu ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Menu));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(280, 180, 30, 20, "Ctrl");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Control_R));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(325, 180, 20, 20, "@4->");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(10);
      o->labelcolor(FL_DARK1);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Left));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(345, 180, 20, 20, "@2->");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(10);
      o->labelcolor(FL_DARK1);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Down));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(365, 180, 20, 20, "@6->");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(10);
      o->labelcolor(FL_DARK1);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Right));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 180, 40, 20, "0");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'0'));
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 180, 20, 20, ".");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'.'));
    } // Fl_Button* o
    { Fl_Box* o = new Fl_Box(400, 15, 80, 0, "Fl::event_state():");
      o->labelsize(9);
      o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Box* o
    { Fl_Button* o = new Fl_Button(400, 15, 20, 10, "shift ");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_SHIFT));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 15, 20, 10, "lock ");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_CAPS_LOCK));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 15, 20, 10, "ctrl");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_CTRL));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(460, 15, 20, 10, "alt");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_ALT));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 25, 20, 10, "num");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_NUM_LOCK));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 25, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x20));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 25, 20, 10, "meta ");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_META));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(460, 25, 20, 10, "sclk");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_SCROLL_LOCK));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 35, 20, 10, "b1");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_BUTTON1));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 35, 20, 10, "b2");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_BUTTON2));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 35, 20, 10, "b3");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_BUTTON3));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(460, 35, 20, 10, "bck");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_BUTTON4));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(400, 45, 20, 10, "fwd");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_BUTTON5));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(420, 45, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x2000));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(440, 45, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x4000));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(460, 45, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color((Fl_Color)3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x8000));
    } // Fl_Button* o
    my_window->end();
  } // MyWindow* my_window
  return my_window;
}
