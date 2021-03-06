// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef MasterUI_h
#define MasterUI_h
#include <FL/Fl.H>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "WidgetPDial.h"
#include "ADnoteUI.h"
#include "SUBnoteUI.h"
#include "EffUI.h"
#include "VirKeyboard.h"
#include "ConfigUI.h"
#include "BankUI.h"
#include "PartUI.h"
#include "MicrotonalUI.h"
#include "SeqUI.h"
#include "PresetsUI.h"
#include "../Misc/Master.h"
#include "../Misc/Part.h"
#include "../Misc/Util.h"
#include "../globals.h"

class VUMeter : public Fl_Box {
public:
  VUMeter(int x,int y, int w, int h, const char *label=0);
  void init(Master *master_,int part_);
  void draw_master();
  void draw_part();
  void draw();
  static void tickdraw(VUMeter *o);
  static void tick(void *v);
  int handle(int event);
private:
  Master *master; 
  int npart; 
  float olddbl,olddbr; 
  float oldrmsdbl,oldrmsdbr; 
};

class SysEffSend : public WidgetPDial {
public:
  SysEffSend(int x,int y, int w, int h, const char *label=0);
  void init(Master *master_,int neff1_,int neff2_);
  ~SysEffSend();
  int handle(int event);
private:
  Master *master; 
  int neff1; 
  int neff2; 
};
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>

class Panellistitem : public Fl_Group {
  Fl_Group* make_window();
  Fl_Group *panellistitem;
  Fl_Group *panellistitemgroup;
public:
  Fl_Button *partname;
private:
  void cb_partname_i(Fl_Button*, void*);
  static void cb_partname(Fl_Button*, void*);
public:
  Fl_Slider *partvolume;
private:
  void cb_partvolume_i(Fl_Slider*, void*);
  static void cb_partvolume(Fl_Slider*, void*);
public:
  WidgetPDial *partpanning;
private:
  void cb_partpanning_i(WidgetPDial*, void*);
  static void cb_partpanning(WidgetPDial*, void*);
  void cb_edit_i(Fl_Button*, void*);
  static void cb_edit(Fl_Button*, void*);
public:
  Fl_Choice *partrcv;
private:
  void cb_partrcv_i(Fl_Choice*, void*);
  static void cb_partrcv(Fl_Choice*, void*);
  Fl_Check_Button *partenabled;
  void cb_partenabled_i(Fl_Check_Button*, void*);
  static void cb_partenabled(Fl_Check_Button*, void*);
public:
  Panellistitem(int x,int y, int w, int h, const char *label=0);
  void init(Master *master_, int npart_,BankUI *bankui_);
  void refresh();
  ~Panellistitem();
private:
  int npart; 
  Master *master; 
  BankUI *bankui; 
};
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Counter.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Pack.H>

class MasterUI {
public:
  Fl_Double_Window* make_window();
  Fl_Double_Window *masterwindow;
private:
  void cb_masterwindow_i(Fl_Double_Window*, void*);
  static void cb_masterwindow(Fl_Double_Window*, void*);
public:
  Fl_Menu_Bar *mastermenu;
  static Fl_Menu_Item menu_mastermenu[];
private:
  void cb_New_i(Fl_Menu_*, void*);
  static void cb_New(Fl_Menu_*, void*);
  void cb_Open_i(Fl_Menu_*, void*);
  static void cb_Open(Fl_Menu_*, void*);
  void cb_Save_i(Fl_Menu_*, void*);
  static void cb_Save(Fl_Menu_*, void*);
  void cb_Load_i(Fl_Menu_*, void*);
  static void cb_Load(Fl_Menu_*, void*);
  void cb_Save1_i(Fl_Menu_*, void*);
  static void cb_Save1(Fl_Menu_*, void*);
  void cb_Show_i(Fl_Menu_*, void*);
  static void cb_Show(Fl_Menu_*, void*);
  void cb_Settings_i(Fl_Menu_*, void*);
  static void cb_Settings(Fl_Menu_*, void*);
  void cb_Copyright_i(Fl_Menu_*, void*);
  static void cb_Copyright(Fl_Menu_*, void*);
  void cb_E_i(Fl_Menu_*, void*);
  static void cb_E(Fl_Menu_*, void*);
  void cb_Clear_i(Fl_Menu_*, void*);
  static void cb_Clear(Fl_Menu_*, void*);
  void cb_Open1_i(Fl_Menu_*, void*);
  static void cb_Open1(Fl_Menu_*, void*);
  void cb_Save2_i(Fl_Menu_*, void*);
  static void cb_Save2(Fl_Menu_*, void*);
  void cb_Show1_i(Fl_Menu_*, void*);
  static void cb_Show1(Fl_Menu_*, void*);
  void cb_Virtual_i(Fl_Menu_*, void*);
  static void cb_Virtual(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *recordmenu;
private:
  void cb_Choose_i(Fl_Menu_*, void*);
  static void cb_Choose(Fl_Menu_*, void*);
  void cb_Show2_i(Fl_Menu_*, void*);
  static void cb_Show2(Fl_Menu_*, void*);
  void cb_Switch_i(Fl_Menu_*, void*);
  static void cb_Switch(Fl_Menu_*, void*);
public:
  WidgetPDial *mastervolumedial;
private:
  void cb_mastervolumedial_i(WidgetPDial*, void*);
  static void cb_mastervolumedial(WidgetPDial*, void*);
public:
  Fl_Counter *masterkeyshiftcounter;
private:
  void cb_masterkeyshiftcounter_i(Fl_Counter*, void*);
  static void cb_masterkeyshiftcounter(Fl_Counter*, void*);
  void cb_Panic_i(Fl_Button*, void*);
  static void cb_Panic(Fl_Button*, void*);
public:
  Fl_Group *partuigroup;
  PartUI *partui;
  Fl_Counter *syseffnocounter;
private:
  void cb_syseffnocounter_i(Fl_Counter*, void*);
  static void cb_syseffnocounter(Fl_Counter*, void*);
public:
  Fl_Choice *sysefftype;
private:
  void cb_sysefftype_i(Fl_Choice*, void*);
  static void cb_sysefftype(Fl_Choice*, void*);
  static Fl_Menu_Item menu_sysefftype[];
public:
  Fl_Group *syseffectuigroup;
  EffUI *syseffectui;
private:
  void cb_Send_i(Fl_Button*, void*);
  static void cb_Send(Fl_Button*, void*);
  void cb_C_i(Fl_Button*, void*);
  static void cb_C(Fl_Button*, void*);
  void cb_P_i(Fl_Button*, void*);
  static void cb_P(Fl_Button*, void*);
public:
  Fl_Counter *inseffnocounter;
private:
  void cb_inseffnocounter_i(Fl_Counter*, void*);
  static void cb_inseffnocounter(Fl_Counter*, void*);
public:
  Fl_Choice *insefftype;
private:
  void cb_insefftype_i(Fl_Choice*, void*);
  static void cb_insefftype(Fl_Choice*, void*);
  static Fl_Menu_Item menu_insefftype[];
public:
  Fl_Group *inseffectuigroup;
  EffUI *inseffectui;
  Fl_Choice *inseffpart;
private:
  void cb_inseffpart_i(Fl_Choice*, void*);
  static void cb_inseffpart(Fl_Choice*, void*);
  void cb_C1_i(Fl_Button*, void*);
  static void cb_C1(Fl_Button*, void*);
  void cb_P1_i(Fl_Button*, void*);
  static void cb_P1(Fl_Button*, void*);
  void cb_Scales_i(Fl_Button*, void*);
  static void cb_Scales(Fl_Button*, void*);
public:
  Fl_Button *recordbutton;
private:
  void cb_recordbutton_i(Fl_Button*, void*);
  static void cb_recordbutton(Fl_Button*, void*);
public:
  Fl_Button *stopbutton;
private:
  void cb_stopbutton_i(Fl_Button*, void*);
  static void cb_stopbutton(Fl_Button*, void*);
public:
  Fl_Button *pausebutton;
private:
  void cb_pausebutton_i(Fl_Button*, void*);
  static void cb_pausebutton(Fl_Button*, void*);
public:
  Fl_Box *pauselabel;
  Fl_Check_Button *nrpnbutton;
private:
  void cb_nrpnbutton_i(Fl_Check_Button*, void*);
  static void cb_nrpnbutton(Fl_Check_Button*, void*);
public:
  Fl_Counter *npartcounter;
private:
  void cb_npartcounter_i(Fl_Counter*, void*);
  static void cb_npartcounter(Fl_Counter*, void*);
  void cb_vK_i(Fl_Button*, void*);
  static void cb_vK(Fl_Button*, void*);
  void cb_R_i(Fl_Button*, void*);
  static void cb_R(Fl_Button*, void*);
public:
  WidgetPDial *globalfinedetuneslider;
private:
  void cb_globalfinedetuneslider_i(WidgetPDial*, void*);
  static void cb_globalfinedetuneslider(WidgetPDial*, void*);
  void cb_Panel_i(Fl_Button*, void*);
  static void cb_Panel(Fl_Button*, void*);
public:
  Fl_Double_Window *aboutwindow;
private:
  void cb_Close_i(Fl_Button*, void*);
  static void cb_Close(Fl_Button*, void*);
public:
  Fl_Double_Window *syseffsendwindow;
private:
  void cb_Close1_i(Fl_Button*, void*);
  static void cb_Close1(Fl_Button*, void*);
public:
  Fl_Double_Window *panelwindow;
private:
  void cb_Close2_i(Fl_Button*, void*);
  static void cb_Close2(Fl_Button*, void*);
  void cb_Refresh_i(Fl_Button*, void*);
  static void cb_Refresh(Fl_Button*, void*);
public:
  Fl_Double_Window *simplemasterwindow;
private:
  void cb_simplemasterwindow_i(Fl_Double_Window*, void*);
  static void cb_simplemasterwindow(Fl_Double_Window*, void*);
  static Fl_Menu_Item menu_[];
  void cb_New1_i(Fl_Menu_*, void*);
  static void cb_New1(Fl_Menu_*, void*);
  void cb_Open2_i(Fl_Menu_*, void*);
  static void cb_Open2(Fl_Menu_*, void*);
  void cb_Save3_i(Fl_Menu_*, void*);
  static void cb_Save3(Fl_Menu_*, void*);
  void cb_Settings1_i(Fl_Menu_*, void*);
  static void cb_Settings1(Fl_Menu_*, void*);
  void cb_Copyright1_i(Fl_Menu_*, void*);
  static void cb_Copyright1(Fl_Menu_*, void*);
  void cb_E1_i(Fl_Menu_*, void*);
  static void cb_E1(Fl_Menu_*, void*);
  void cb_Open3_i(Fl_Menu_*, void*);
  static void cb_Open3(Fl_Menu_*, void*);
  void cb_Show3_i(Fl_Menu_*, void*);
  static void cb_Show3(Fl_Menu_*, void*);
  void cb_Switch1_i(Fl_Menu_*, void*);
  static void cb_Switch1(Fl_Menu_*, void*);
  Fl_Group *simplelistitemgroup;
public:
  Fl_Button *partname;
private:
  void cb_partname1_i(Fl_Button*, void*);
  static void cb_partname1(Fl_Button*, void*);
public:
  Fl_Slider *partpanning;
private:
  void cb_partpanning1_i(Fl_Slider*, void*);
  static void cb_partpanning1(Fl_Slider*, void*);
public:
  Fl_Choice *partrcv;
private:
  void cb_partrcv1_i(Fl_Choice*, void*);
  static void cb_partrcv1(Fl_Choice*, void*);
public:
  WidgetPDial *partvolume;
private:
  void cb_partvolume1_i(WidgetPDial*, void*);
  static void cb_partvolume1(WidgetPDial*, void*);
public:
  Fl_Check_Button *simplepartportamento;
private:
  void cb_simplepartportamento_i(Fl_Check_Button*, void*);
  static void cb_simplepartportamento(Fl_Check_Button*, void*);
public:
  Fl_Counter *simpleminkcounter;
private:
  void cb_simpleminkcounter_i(Fl_Counter*, void*);
  static void cb_simpleminkcounter(Fl_Counter*, void*);
public:
  Fl_Counter *simplemaxkcounter;
private:
  void cb_simplemaxkcounter_i(Fl_Counter*, void*);
  static void cb_simplemaxkcounter(Fl_Counter*, void*);
  void cb_m_i(Fl_Button*, void*);
  static void cb_m(Fl_Button*, void*);
  void cb_M_i(Fl_Button*, void*);
  static void cb_M(Fl_Button*, void*);
  void cb_R1_i(Fl_Button*, void*);
  static void cb_R1(Fl_Button*, void*);
public:
  Fl_Counter *simplepartkeyshiftcounter;
private:
  void cb_simplepartkeyshiftcounter_i(Fl_Counter*, void*);
  static void cb_simplepartkeyshiftcounter(Fl_Counter*, void*);
public:
  WidgetPDial *simplesyseffsend;
private:
  void cb_simplesyseffsend_i(WidgetPDial*, void*);
  static void cb_simplesyseffsend(WidgetPDial*, void*);
  Fl_Check_Button *partenabled;
  void cb_partenabled1_i(Fl_Check_Button*, void*);
  static void cb_partenabled1(Fl_Check_Button*, void*);
public:
  VirKeys *virkeys;
  Fl_Counter *simplesyseffnocounter;
private:
  void cb_simplesyseffnocounter_i(Fl_Counter*, void*);
  static void cb_simplesyseffnocounter(Fl_Counter*, void*);
public:
  Fl_Choice *simplesysefftype;
private:
  void cb_simplesysefftype_i(Fl_Choice*, void*);
  static void cb_simplesysefftype(Fl_Choice*, void*);
  static Fl_Menu_Item menu_simplesysefftype[];
public:
  Fl_Group *simplesyseffectuigroup;
  SimpleEffUI *simplesyseffectui;
private:
  void cb_Send1_i(Fl_Button*, void*);
  static void cb_Send1(Fl_Button*, void*);
  void cb_P2_i(Fl_Button*, void*);
  static void cb_P2(Fl_Button*, void*);
public:
  Fl_Counter *simpleinseffnocounter;
private:
  void cb_simpleinseffnocounter_i(Fl_Counter*, void*);
  static void cb_simpleinseffnocounter(Fl_Counter*, void*);
public:
  Fl_Choice *simpleinsefftype;
private:
  void cb_simpleinsefftype_i(Fl_Choice*, void*);
  static void cb_simpleinsefftype(Fl_Choice*, void*);
  static Fl_Menu_Item menu_simpleinsefftype[];
public:
  Fl_Group *simpleinseffectuigroup;
  SimpleEffUI *simpleinseffectui;
  Fl_Choice *simpleinseffpart;
private:
  void cb_simpleinseffpart_i(Fl_Choice*, void*);
  static void cb_simpleinseffpart(Fl_Choice*, void*);
  void cb_P3_i(Fl_Button*, void*);
  static void cb_P3(Fl_Button*, void*);
public:
  WidgetPDial *simplemastervolumedial;
private:
  void cb_simplemastervolumedial_i(WidgetPDial*, void*);
  static void cb_simplemastervolumedial(WidgetPDial*, void*);
public:
  Fl_Counter *simplemasterkeyshiftcounter;
private:
  void cb_simplemasterkeyshiftcounter_i(Fl_Counter*, void*);
  static void cb_simplemasterkeyshiftcounter(Fl_Counter*, void*);
  void cb_Stop_i(Fl_Button*, void*);
  static void cb_Stop(Fl_Button*, void*);
  void cb_Reset_i(Fl_Button*, void*);
  static void cb_Reset(Fl_Button*, void*);
public:
  WidgetPDial *simpleglobalfinedetuneslider;
private:
  void cb_simpleglobalfinedetuneslider_i(WidgetPDial*, void*);
  static void cb_simpleglobalfinedetuneslider(WidgetPDial*, void*);
public:
  Fl_Counter *simplenpartcounter;
private:
  void cb_simplenpartcounter_i(Fl_Counter*, void*);
  static void cb_simplenpartcounter(Fl_Counter*, void*);
  void cb_Keyb_i(Fl_Counter*, void*);
  static void cb_Keyb(Fl_Counter*, void*);
public:
  Fl_Double_Window *selectuiwindow;
private:
  void cb_selectuiwindow_i(Fl_Double_Window*, void*);
  static void cb_selectuiwindow(Fl_Double_Window*, void*);
  void cb_Advanced_i(Fl_Button*, void*);
  static void cb_Advanced(Fl_Button*, void*);
  void cb_Beginner_i(Fl_Button*, void*);
  static void cb_Beginner(Fl_Button*, void*);
public:
  void updatesendwindow();
  void updatepanel();
  void setfilelabel(const char *filename);
  MasterUI(Master *master_,int *exitprogram_);
  ~MasterUI();
  void showUI();
  void simplerefresh();
  void do_new_master();
  void do_load_master(const char* file = NULL);
  void do_save_master(const char* file = NULL);
  void refresh_master_ui();
private:
  Master *master; 
  MicrotonalUI *microtonalui; 
  SeqUI *sequi; 
  BankUI *bankui; 
  int ninseff,npart; 
  int nsyseff; 
  int *exitprogram; 
  SysEffSend *syseffsend[NUM_SYS_EFX][NUM_SYS_EFX]; 
  VirKeyboard *virkeyboard; 
  ConfigUI *configui; 
  int swapefftype; 
  char masterwindowlabel[100]; 
  Panellistitem *panellistitem[NUM_MIDI_PARTS]; 
};
#endif
