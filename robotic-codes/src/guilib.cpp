#include "guilib.hpp"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

namespace guilib
{
  void viewport(int x1, int y1, int x2, int y2)
  {
    if (!graphix)
      exit;
  }
  void main_viewport()
  {

  }
  void textxy(int x, int y, string s)
  {
    // draw text on top of a graphical box
    setfillstyle(1,0);
    bar(x,y,x+s.length()*8, y+7);
    outtextxy(x,y,s);
  }
  void coltextxy(int x, int y, string s, byte c)
  {
      textxy(x,y,s);
  }
  void box(int x1, int y1, int x2, int y2){

  }
  void hole(int x1, int y1, int x2, int y2){

  }
  void chirp(){

  }
  void click(){

  }

}

procedure draw_robot(n:integer);
var
{
 i,t:integer;
 xx,yy:real;
begin
 if not (n in [0..num_robots]) then exit;
 with robot[n]^ do
  begin
   if x>1000 then x:=1000;
   if y>1000 then y:=1000;
   if x<0 then x:=0;
   if y<0 then y:=0;
   {if (lhd=hd) and (lx=x) and (ly=y) then exit;}

   {--set up for erase--}
   {xx:=lx*screen_scale; yy:=ly*screen_scale;
   lhd:=(lhd+1024) and 255;
   ltx[1]:=round(xx+sint[lhd]*robot_scale);
   lty[1]:=round(yy-cost[lhd]*robot_scale);
   ltx[2]:=round(xx+sint[(lhd+$68) and 255]*robot_scale);
   lty[2]:=round(yy-cost[(lhd+$68) and 255]*robot_scale);
   ltx[3]:=round(xx+sint[(lhd+$98) and 255]*robot_scale);
   lty[3]:=round(yy-cost[(lhd+$98) and 255]*robot_scale);
   t:=(lhd+(lshift and 255)+1024) and 255;
   ltx[4]:=round(xx+sint[t and 255]*robot_scale);
   lty[4]:=round(yy-cost[t and 255]*robot_scale);}

   {--set up for draw--}
   xx:=x*screen_scale+screen_x; yy:=y*screen_scale+screen_y;
   hd:=(hd+1024) and 255;
   tx[1]:=round(xx+sint[hd]*5);
   ty[1]:=round(yy-cost[hd]*5);
   tx[2]:=round(xx+sint[(hd+$68) and 255]*robot_scale);
   ty[2]:=round(yy-cost[(hd+$68) and 255]*robot_scale);
   tx[3]:=round(xx+sint[(hd+$98) and 255]*robot_scale);
   ty[3]:=round(yy-cost[(hd+$98) and 255]*robot_scale);
   t:=(hd+(shift and 255)+1024) and 255;
   tx[4]:=round(xx); ty[4]:=round(yy);
   tx[5]:=round(xx+sint[t]*robot_scale*0.8);
   ty[5]:=round(yy-cost[t]*robot_scale*0.8);
   tx[6]:=round(xx+sint[(t+scanarc+1024) and 255]*scanrange*screen_scale);
   ty[6]:=round(yy-cost[(t+scanarc+1024) and 255]*scanrange*screen_scale);
   tx[7]:=round(xx+sint[(t-scanarc+1024) and 255]*scanrange*screen_scale);
   ty[7]:=round(yy-cost[(t-scanarc+1024) and 255]*scanrange*screen_scale);
   startarc:=round(((256-((t+scanarc+1024) and 255))/256*360)+90);
   endarc:=round(((256-((t-scanarc+1024) and 255))/256*360)+90);


   if graphix then
    begin
     main_viewport;
     {--erase--}
     setcolor(0);
     if lshields then
        circle(ltx[4],lty[4],robot_scale);
     if (arc_count>0) then
      begin
       line(ltx[4],lty[4],ltx[6],lty[6]);
       line(ltx[4],lty[4],ltx[7],lty[7]);
       if scanrange<1500 then
          arc(ltx[4],lty[4],lstartarc,lendarc,round(scanrange*screen_scale));
      end;
     if (sonar_count>0) then
      begin
       circle(ltx[4],lty[4],round(max_sonar*screen_scale));
      end;
     if armor>0 then
      begin {only erase body if still alive, that way we leave a "corpse" when dead}
       line(ltx[1],lty[1],ltx[2],lty[2]);
       line(ltx[2],lty[2],ltx[3],lty[3]);
       line(ltx[3],lty[3],ltx[1],lty[1]);
       line(ltx[4],lty[4],ltx[5],lty[5]);
      end;
    end;
   if armor>0 then //If we're still alive we need to redraw
    begin
     if arc_count>0   then dec(arc_count);
     if sonar_count>0 then dec(sonar_count);
     if graphix then
      begin
       {--draw--}
       setcolor(robot_color(n) and 7);
       if shields_up then
        circle(tx[4],ty[4],robot_scale);
       setcolor(robot_color(n));
       line(tx[1],ty[1],tx[2],ty[2]);
       line(tx[2],ty[2],tx[3],ty[3]);
       line(tx[3],ty[3],tx[1],ty[1]);
       setcolor(7);
       line(tx[4],ty[4],tx[5],ty[5]);
       setcolor(8);
       if show_arcs and (arc_count>0) then
        begin
         line(tx[4],ty[4],tx[6],ty[6]);
         line(tx[4],ty[4],tx[7],ty[7]);
         if scanrange<1500 then
            arc(tx[4],ty[4],startarc,endarc,round(scanrange*screen_scale));
        end;
       if show_arcs and (sonar_count>0) then
          circle(tx[4],ty[4],round(max_sonar*screen_scale));
     end;
     lx:=x; ly:=y; lhd:=hd; lshift:=shift; lshields:=shields_up;
     for i:=1 to max_robot_lines do
      begin ltx[i]:=tx[i]; lty[i]:=ty[i]; end;
     lstartarc:=startarc; lendarc:=endarc;
    end;
  end;
end;
}

procedure damage(n,d:integer; physical:boolean);
var
 i,k,h,dd:integer;
 m:real;
begin
 if (n<0) or (n>num_robots) or (robot[n]^.armor<=0) then exit;
 if robot[n]^.config.shield<3 then robot[n]^.shields_up:=false;
 with robot[n]^ do
  begin
   h:=0;
   if (shields_up) and (not physical) then
    begin
     dd:=d;
     if (old_shields) and (config.shield>=3) then begin d:=0; h:=0; end
      else case config.shield of
       3:begin d:=round(dd*2/3); if d<1 then d:=1; h:=round(dd*2/3); end;
       4:begin h:=trunc(dd/2); d:=dd-h; end;
       5:begin d:=round(dd*1/3); if d<1 then d:=1;
               h:=round(dd*1/3); if h<1 then h:=1; end;
      end;
    end;
   if d<0 then d:=0;
   if debug_info then
    begin writeln(#13,zero_pad(game_cycle,5),' D ',n,': ',armor,'-',d,'=',armor-d,'           ');
    repeat until keypressed; flushkey; end;
   if d>0 then
    begin d:=round(d*damageadj); if d<1 then d:=1; end;
   dec(armor,d);
   inc(heat,h);
   last_damage:=0;
   if armor<=0 then
    begin
     armor:=0;
     update_armor(n);
     heat:=500;
     update_heat(n);
     armor:=0;
     inc(kill_count);
     inc(deaths);
     update_lives(n);
     if graphix and timing then time_delay(10);
     draw_robot(n);
     heat:=0;
     update_heat(n);
     init_missile(x,y,0,0,0,n,blast_circle,false);
     if overburn then m:=1.3 else m:=1;
     for i:=0 to num_robots do
      if (i<>n) and (robot[i]^.armor>0) then
       begin
        k:=round(distance(x,y,robot[i]^.x,robot[i]^.y));
        if k<blast_radius then
         damage(i,round(abs(blast_radius-k)*m),false);
       end;
    end;
  end;
end;



procedure update_debug_bars;
begin
 if graphix and (step_mode>0) then with robot[0]^ do
  begin
   {debugger window}
   viewport(480,4,635,410);

   {armour}
   setfillstyle(1,robot_color(0));
   if armor>0 then
    bar(88,03,87+(armor shr 2),08);
   setfillstyle(1,8);
   if armor<100 then
    bar(88+(armor shr 2),03,111,08);

   {heat}
   setfillstyle(1,robot_color(0));
   if heat>5 then
    bar(127,03,126+(heat div 20),08);
   setfillstyle(1,8);
   if heat<500 then
    bar(127+(heat div 20),03,151,08);
  end;
end;



procedure update_debug_system;
var
 i:integer;
begin
 if graphix and (step_mode>0) then with robot[0]^ do
  begin
   {debugger window}
   viewport(480,4,635,410);
   setfillstyle(1,0);
   {for i:=0 to 6 do
    begin
     bar(039,32+(i*10),70,39+(i*10));
     bar(110,32+(i*10),141,39+(i*10));
    end;} {Commented out the black bars, and switched to 'textxy' -Bones}
   setcolor(robot_color(0));
   textxy(039,32,hex(ram[0])); textxy(110,32,hex(ram[7]));
   textxy(039,42,hex(ram[1])); textxy(110,42,hex(ram[8]));
   textxy(039,52,hex(ram[2])); textxy(110,52,hex(ram[9]));
   textxy(039,62,hex(ram[3])); textxy(110,62,hex(ram[10]));
   textxy(039,72,hex(ram[4])); textxy(110,72,hex(ram[11]));
   textxy(039,82,hex(ram[5])); textxy(110,82,hex(ram[12]));
   textxy(039,92,hex(ram[6])); textxy(110,92,hex(ram[13]));
  end;
end;

procedure update_debug_registers;
var
 i:integer;
begin
 if graphix and (step_mode>0) then with robot[0]^ do
  begin
   {debugger window}
   viewport(480,4,635,410);
   setfillstyle(1,0);
   {for i:=0 to 4 do
    begin
     bar(039,122+(i*10),70,129+(i*10));
     bar(110,122+(i*10),141,129+(i*10));
    end;} {Commented out the black bars, and switched to 'textxy' -Bones}
   setcolor(robot_color(0));
   textxy(039,122,hex(ram[65])); textxy(110,122,hex(ram[69]));
   textxy(039,132,hex(ram[66])); textxy(110,132,hex(ram[70]));
   textxy(039,142,hex(ram[67]));
   textxy(039,152,hex(ram[68])); textxy(110,152,hex(ram[71]));
  end;
end;

procedure update_debug_flags;
var
bin_string:string;
begin
 if graphix and (step_mode>0) then with robot[0]^ do
  begin
   {debugger window}
   viewport(480,4,635,410);
   bin_string:=bin(ram[64]);
   if bin_string[13]='1' then setcolor(robot_color(0)) else setcolor(robot_color(8));
   outtextxy(111,172,'Z');
   if bin_string[14]='1' then setcolor(robot_color(0)) else setcolor(robot_color(8));
   outtextxy(119,172,'G');
   if bin_string[15]='1' then setcolor(robot_color(0)) else setcolor(robot_color(8));
   outtextxy(127,172,'L');
   if bin_string[16]='1' then setcolor(robot_color(0)) else setcolor(robot_color(8));
   outtextxy(135,172,'E');
   {setfillstyle(1,0);
   bar(015,182,142,189);
   setcolor(robot_color(0));}
   {Commented out the black bars, and switched to 'textxy' -Bones}
   textxy(015,182,bin(ram[64]));
  end;
end;


procedure update_debug_memory;
var
 i:integer;
begin
 if graphix and (step_mode>0) then with robot[0]^ do
  begin
   {debugger window}
   viewport(480,4,635,410);
   {setfillstyle(1,0);
   for i:=0 to 9 do
    bar(091,212+(i*10),123,222+(i*10));}
    {Commented out the black bars, and switched to 'textxy' -Bones}
   setcolor(robot_color(0));
   for i:=0 to 9 do
    if ((mem_watch+i)>=0) and ((mem_watch+i)<=1023) then
     begin
      textxy(035,212+(10*i),decimal((mem_watch+i),4) + ' :');
      textxy(091,212+(10*i),hex(ram[mem_watch+i]));
     end;
  end;
end;


procedure update_debug_code;
var
 i:integer;
begin
 if graphix and (step_mode>0) then with robot[0]^ do
  begin
   {debugger window}
   viewport(480,4,635,410);
   {code}
   {setfillstyle(1,0);
   for i:=0 to 6 do bar(003,332+(i*10),152,340+(i*10));}
   {Commented out the black bars, and switched to 'textxy' -Bones}
   setcolor(7);
   for i:=0 to 6 do
    if (ip+i-3)>=0 then
     begin
      if i=3 then setcolor(robot_color(0));
      textxy(003,332+(i*10),decimal(ip+i-3,4)+': '
            +mnemonic(code[ip+i-3].op[0],code[ip+i-3].op[3] and 15)+' '
            +operand(code[ip+i-3].op[1],(code[ip+i-3].op[3] shr 4) and 15)+','
            +operand(code[ip+i-3].op[2],(code[ip+i-3].op[3] shr 8) and 15));
      if i=3 then setcolor(7);
     end;
  end;
end;


procedure update_debug_window;
begin
 if graphix and (step_mode>0) then
  begin

   {armour + heat}
   update_debug_bars;

   {system variables}
   update_debug_system;

   {registers}
   update_debug_registers;

   {flag register}
   update_debug_flags;

   {memory}
   update_debug_memory;

   {code}
   update_debug_code;

  end;
end;


procedure init_debug_window;
var i:integer;
begin
 if graphix then
 begin

 {debugger window}
 viewport(480,4,635,430);
 setfillstyle(1,7);
 bar(0,0,155,422);
 viewport(480,4,635,410);
 hole(0,0,155,402);

 with robot[0]^ do
  begin
   setcolor(robot_color(0));
   outtextxy(003,02,base_name(no_path(fn)));

   {armour}
   outtextxy(080,02,'A');
   setfillstyle(1,robot_color(0));

   {heat}
   outtextxy(118,02,'H');
   setfillstyle(1,robot_color(0));

   {system variables}
   setcolor(robot_color(8));
   outtextxy(007,22,'System:');
   setcolor(robot_color(0));
   outtextxy(015,32,'00:      07:');
   outtextxy(015,42,'01:      08:');
   outtextxy(015,52,'02:      09:');
   outtextxy(015,62,'03:      10:');
   outtextxy(015,72,'04:      11:');
   outtextxy(015,82,'05:      12:');
   outtextxy(015,92,'06:      13:');

   {registers}
   setcolor(robot_color(8));
   outtextxy(007,112,'Registers:');
   setcolor(robot_color(0));
   outtextxy(015,122,'ax:      ex:');
   outtextxy(015,132,'bx:      fx:');
   outtextxy(015,142,'cx:');
   outtextxy(015,152,'dx:      sp:');

   {flag register}
   setcolor(robot_color(8));
   outtextxy(007,172,'Flags:');

   {memory}
   setcolor(robot_color(8));
   outtextxy(007,202,'Memory:');
   setcolor(7);
   outtextxy(103,202,'-+,[]');
   setcolor(robot_color(0));
   for i:=0 to 9 do
    outtextxy(035,212+(10*i),decimal((mem_watch+i),4) + ' :');

   {code}
   setcolor(robot_color(8));
   outtextxy(007,322,'Code:');

  end;
 update_debug_window;

 end;
end;

procedure init_debug_window;
var i:integer;
begin
 if graphix then
 begin

 {debugger window}
 viewport(480,4,635,430);
 setfillstyle(1,7);
 bar(0,0,155,422);
 viewport(480,4,635,410);
 hole(0,0,155,402);

 with robot[0]^ do
  begin
   setcolor(robot_color(0));
   outtextxy(003,02,base_name(no_path(fn)));

   {armour}
   outtextxy(080,02,'A');
   setfillstyle(1,robot_color(0));

   {heat}
   outtextxy(118,02,'H');
   setfillstyle(1,robot_color(0));

   {system variables}
   setcolor(robot_color(8));
   outtextxy(007,22,'System:');
   setcolor(robot_color(0));
   outtextxy(015,32,'00:      07:');
   outtextxy(015,42,'01:      08:');
   outtextxy(015,52,'02:      09:');
   outtextxy(015,62,'03:      10:');
   outtextxy(015,72,'04:      11:');
   outtextxy(015,82,'05:      12:');
   outtextxy(015,92,'06:      13:');

   {registers}
   setcolor(robot_color(8));
   outtextxy(007,112,'Registers:');
   setcolor(robot_color(0));
   outtextxy(015,122,'ax:      ex:');
   outtextxy(015,132,'bx:      fx:');
   outtextxy(015,142,'cx:');
   outtextxy(015,152,'dx:      sp:');

   {flag register}
   setcolor(robot_color(8));
   outtextxy(007,172,'Flags:');

   {memory}
   setcolor(robot_color(8));
   outtextxy(007,202,'Memory:');
   setcolor(7);
   outtextxy(103,202,'-+,[]');
   setcolor(robot_color(0));
   for i:=0 to 9 do
    outtextxy(035,212+(10*i),decimal((mem_watch+i),4) + ' :');

   {code}
   setcolor(robot_color(8));
   outtextxy(007,322,'Code:');

  end;
 update_debug_window;

 end;
end;


procedure close_debug_window;
var i:integer;
begin
 if graphix then
 begin

 stats_mode:=0;
 case num_robots of
  0..5:stats_mode:=0;
  6..11:stats_mode:=1;
  12..max_robots:stats_mode:=2;
  else stats_mode:=0;
 end;

 viewport(480,4,635,430);
 setfillstyle(1,7);
 bar(0,0,155,426);
{ update_cycle_window;}

 {--robot windows--}
 for i:=0 to max_robots do
  if i<max_shown then with robot[i]^ do
   begin
    robot_graph(i);
    hole(0,0,max_gx,max_gy);
    if i<=num_robots then
     begin
      setcolor(robot_color(i));
      outtextxy(003,02,base_name(no_path(fn)));
      case stats_mode of
       1:begin
          outtextxy(003,12,' A:');
          outtextxy(003,22,' H:');
         end;
       2:begin
          setcolor(robot_color(i) and 7);
          outtextxy(080,02,'A');
          outtextxy(118,02,'H');
         end;
       else begin
          outtextxy(003,24,' A:');
          outtextxy(003,34,' H:');
         end;
      end;
      setcolor(robot_color(i));
      if stats_mode<=1 then
       begin
        outtextxy(080,02,'Wins:');
        outtextxy(122,02,zero_pad(wins,4));
       end;
      if stats_mode=0 then
       begin
        outtextxy(003,56,' Error:');
        setcolor(robot_color(i) and 7);
        outtextxy(003,12,name);
        setcolor(8);
        outtextxy(66,56,'None');
       end;
      lx:=1000-x; ly:=1000-y;
      update_armor(i);
      update_heat(i);
      update_lives(i);
     end
    else
     begin
      setfillpattern(gray50,8);
      bar(1,1,max_gx-1,max_gy-1);
     end;
   end;

 end;
end;

procedure execute_instruction(n:integer);
var
 i,j,k:integer;
 time_used,loc:integer;
 inc_ip:boolean;
 {FIFI}
 c:char;
 {/FIFI}
begin
 with robot[n]^ do
  begin
   {--update system variables--}
   ram[000]:=tspd;
   ram[001]:=thd;
   ram[002]:=shift;
   ram[003]:=accuracy;

   time_used:=1; inc_ip:=true; loc:=0;
   if (ip>plen) or (ip<0) then ip:=0;
   if invalid_microcode(n,ip) then
      begin time_used:=1; robot_error(n,16,hex(code[ip].op[max_op])); end
    else

  {FIFI}
  if graphix and (step_mode>0) and (n=0) then  {if stepping enabled...}
   begin
    inc(step_count);
    update_cycle_window;
    update_debug_window;
    if (step_count mod step_mode)=0 then step_loop:=true else step_loop:=false;
    while step_loop and (not(quit or gameover or bout_over)) do
     if keypressed then with robot[0]^ do
      begin
       c:=upcase(readkey);
       case c of
        'X':begin
             temp_mode:=step_mode;
             step_mode:=0;
             step_loop:=false;
             close_debug_window;
            end;
        ' ':begin step_count:=0; step_loop:=false; end;
        '1'..'9':begin step_mode:=value(c); step_count:=0; step_loop:=false; end;
        '0':begin step_mode:=10; step_count:=0; step_loop:=false; end;
        '-','_':if mem_watch>0 then
                 begin
                  setcolor(0);
                  for i:=0 to 9 do
                   outtextxy(035,212+(10*i),decimal((mem_watch+i),4) + ' :');
                  dec(mem_watch);
                  update_debug_memory;
                 end;
        '+','=':if mem_watch<1014 then
                 begin
                  setcolor(0);
                  for i:=0 to 9 do
                   outtextxy(035,212+(10*i),decimal((mem_watch+i),4) + ' :');
                  inc(mem_watch);
                  update_debug_memory;
                 end;
        '[','{':if mem_watch>0 then
                 begin
                  setcolor(0);
                  for i:=0 to 9 do
                   outtextxy(035,212+(10*i),decimal((mem_watch+i),4) + ' :');
                  dec(mem_watch,10);
                  if mem_watch<0 then mem_watch:=0;
                  update_debug_memory;
                 end;
        ']','}':if mem_watch<1014 then
                 begin
                  setcolor(0);
                  for i:=0 to 9 do
                   outtextxy(035,212+(10*i),decimal((mem_watch+i),4) + ' :');
                  inc(mem_watch,10);
                  if mem_watch>1014 then mem_watch:=1014;
                  update_debug_memory;
                 end;
        'G':begin toggle_graphix; temp_mode:=step_mode; step_mode:=0; step_loop:=false; end;
        else process_keypress(c);
       end;
      end;
   end;
   if (not ((code[ip].op[max_op] and 7) in [0,1])) then
      begin time_used:=0; end
    else
   case get_val(n,ip,0) of
    00:begin (*NOP*)
        inc(executed);
       end;
    01:begin (*ADD*)
        put_val(n,ip,1,get_val(n,ip,1)+get_val(n,ip,2));
        inc(executed);
       end;
    02:begin (*SUB*)
        put_val(n,ip,1,get_val(n,ip,1)-get_val(n,ip,2));
        inc(executed);
       end;
    03:begin (*OR*)
        put_val(n,ip,1,get_val(n,ip,1) or get_val(n,ip,2));
        inc(executed);
       end;
    04:begin (*AND*)
        put_val(n,ip,1,get_val(n,ip,1) and get_val(n,ip,2));
        inc(executed);
       end;
    05:begin (*XOR*)
        put_val(n,ip,1,get_val(n,ip,1) xor get_val(n,ip,2));
        inc(executed);
       end;
    06:begin (*NOT*)
        put_val(n,ip,1,not(get_val(n,ip,1)));
        inc(executed);
       end;
    07:begin (*MPY*)
        put_val(n,ip,1,get_val(n,ip,1)*get_val(n,ip,2));
        time_used:=10;
        inc(executed);
       end;
    08:begin (*DIV*)
        j:=get_val(n,ip,2);
        if j<>0 then put_val(n,ip,1,get_val(n,ip,1) div j)
                else robot_error(n,8,'');
        time_used:=10;
        inc(executed);
       end;
    09:begin (*MOD*)
        j:=get_val(n,ip,2);
        if j<>0 then put_val(n,ip,1,get_val(n,ip,1) mod j)
                else robot_error(n,8,'');
        time_used:=10;
        inc(executed);
       end;
    10:begin (*RET*)
        ip:=pop(n);
        if (ip<0) or (ip>plen) then robot_error(n,7,cstr(ip));
        inc(executed);
       end;
    11:begin (*GSB*)
        loc:=find_label(n,get_val(n,ip,1),code[ip].op[max_op] shr (1*4));
        if loc>=0 then begin push(n,ip); inc_ip:=false; ip:=loc; end
                  else robot_error(n,2,cstr(get_val(n,ip,1)));
        inc(executed);
       end;
    12:begin (*JMP*)
        jump(n,1,inc_ip);
        inc(executed);
       end;
    13:begin (*JLS,JB*)
        if ram[64] and 2>0 then
           jump(n,1,inc_ip);
        time_used:=0;
        inc(executed);
       end;
    14:begin (*JGR,JA*)
        if ram[64] and 4>0 then
           jump(n,1,inc_ip);
        time_used:=0;
        inc(executed);
       end;
    15:begin (*JNE*)
        if ram[64] and 1=0 then
           jump(n,1,inc_ip);
        time_used:=0;
        inc(executed);
       end;
    16:begin (*JEQ,JE*)
        if ram[64] and 1>0 then
           jump(n,1,inc_ip);
        time_used:=0;
        inc(executed);
       end;
    17:begin (*SWAP, XCHG*)
        ram[4]:=get_val(n,ip,1);
        put_val(n,ip,1,get_val(n,ip,2));
        put_val(n,ip,2,ram[4]);
        time_used:=3;
        inc(executed);
       end;
    18:begin (*DO*)
        ram[67]:=get_val(n,ip,1);
        inc(executed);
       end;
    19:begin (*LOOP*)
        dec(ram[67]);
        if ram[67]>0 then
           jump(n,1,inc_ip);
        inc(executed);
       end;
    20:begin (*CMP*)
        k:=get_val(n,ip,1)-get_val(n,ip,2);
        ram[64]:=ram[64] and $FFF0;
        if k=0 then ram[64]:=ram[64] or 1;
        if k<0 then ram[64]:=ram[64] or 2;
        if k>0 then ram[64]:=ram[64] or 4;
        if (get_val(n,ip,2)=0) and (k=0) then
                    ram[64]:=ram[64] or 8;
        inc(executed);
       end;
    21:begin (*TEST*)
        k:=get_val(n,ip,1) and get_val(n,ip,2);
        ram[64]:=ram[64] and $FFF0;
        if k=get_val(n,ip,2) then ram[64]:=ram[64] or 1;
        if k=0               then ram[64]:=ram[64] or 8;
        inc(executed);
       end;
    22:begin (*MOV, SET*)
        put_val(n,ip,1,get_val(n,ip,2));
        inc(executed);
       end;
    23:begin (*LOC*)
        put_val(n,ip,1,code[ip].op[2]);
        time_used:=2;
        inc(executed);
       end;
    24:begin (*GET*)
        k:=get_val(n,ip,2);
        if (k>=0) and (k<=max_ram) then
            put_val(n,ip,1,ram[k])
          else if (k>max_ram) and (k<=(Max_ram+1)+(((max_code+1) shl 3)-1)) then
           begin
            j:=k-max_ram-1;
            put_val(n,ip,1,code[j shr 2].op[j and 3]);
           end
          else robot_error(n,4,cstr(k));
        time_used:=2;
        inc(executed);
       end;
    25:begin (*PUT*)
        k:=get_val(n,ip,2);
        if (k>=0) and (k<=max_ram) then
            ram[k]:=get_val(n,ip,1)
          else robot_error(n,4,cstr(k));
        time_used:=2;
        inc(executed);
       end;
    26:begin (*INT*)
        call_int(n,get_val(n,ip,1),time_used);
        inc(executed);
       end;
    27:begin (*IPO,IN*)
        time_used:=4;
        put_val(n,ip,2,in_port(n,get_val(n,ip,1),time_used));
        inc(executed);
       end;
    28:begin (*OPO,OUT*)
        time_used:=4;
        out_port(n,get_val(n,ip,1),get_val(n,ip,2),time_used);
        inc(executed);
       end;
    29:begin (*DEL,DELAY*)
        time_used:=get_val(n,ip,1);
        inc(executed);
       end;
    30:begin (*PUSH*)
        push(n,get_val(n,ip,1));
        inc(executed);
       end;
    31:begin (*POP*)
        put_val(n,ip,1,pop(n));
        inc(executed);
       end;
    32:begin (*ERR*)
        robot_error(n,get_val(n,ip,1),'');
        time_used:=0;
        inc(executed);
       end;
    33:begin (*INC*)
        put_val(n,ip,1,get_val(n,ip,1)+1);
        inc(executed);
       end;
    34:begin (*DEC*)
        put_val(n,ip,1,get_val(n,ip,1)-1);
        inc(executed);
       end;
    35:begin (*SHL*)
        put_val(n,ip,1,get_val(n,ip,1) shl get_val(n,ip,2));
        inc(executed);
       end;
    36:begin (*SHR*)
        put_val(n,ip,1,get_val(n,ip,1) shr get_val(n,ip,2));
        inc(executed);
       end;
    37:begin (*ROL*)
        put_val(n,ip,1,rol(get_val(n,ip,1),get_val(n,ip,2)));
        inc(executed);
       end;
    38:begin (*ROR*)
        put_val(n,ip,1,ror(get_val(n,ip,1),get_val(n,ip,2)));
        inc(executed);
       end;
    39:begin (*JZ*)
        time_used:=0;
        if ram[64] and 8>0 then
           jump(n,1,inc_ip);
        inc(executed);
       end;
    40:begin (*JNZ*)
        time_used:=0;
        if ram[64] and 8=0 then
           jump(n,1,inc_ip);
        inc(executed);
       end;
    41:begin (*JAE,JGE*)
        if (ram[64] and 1>0) or (ram[64] and 4>0) then
           jump(n,1,inc_ip);
        time_used:=0;
        inc(executed);
       end;
    42:begin (*JBE,JLE*)
        if (ram[64] and 1>0) or (ram[64] and 2>0) then
           jump(n,1,inc_ip);
        time_used:=0;
        inc(executed);
       end;
    43:begin (*SAL*)
        put_val(n,ip,1,sal(get_val(n,ip,1),get_val(n,ip,2)));
        inc(executed);
       end;
    44:begin (*SAR*)
        put_val(n,ip,1,sar(get_val(n,ip,1),get_val(n,ip,2)));
        inc(executed);
       end;
    45:begin (*NEG*)
        put_val(n,ip,1,0-get_val(n,ip,1));
        inc(executed);
       end;
    46:begin (*JTL*)
        loc:=get_val(n,ip,1);
        if (loc>=0) and (loc<=plen) then begin inc_ip:=false; ip:=loc; end
                                    else robot_error(n,2,cstr(loc));
       end;
    else begin robot_error(n,6,''); end;
   end;
   inc(delay_left,time_used);
   if inc_ip then inc(ip);
   {FIFI}
   if graphix and (n=0) and (step_mode>0) then update_debug_window;
   {/FIFI}
  end;
end;

procedure do_robot(n:integer);
var
 i,j,k,l,tthd:integer;
 heat_mult,ttx,tty:real;
begin
 if (n<0) or (n>num_robots) then exit;
 with robot[n]^ do
  begin
   if armor<=0 then exit;

   {--time slice--}
   time_left:=time_slice;
   if (time_left>robot_time_limit) and (robot_time_limit>0) then
      time_left:=robot_time_limit;
   if (time_left>max_time) and (max_time>0) then time_left:=max_time;
   executed:=0;

   {--execute timeslice--}
    while (time_left>0) and (not cooling) and (executed<20+time_slice) and (armor>0) do
     begin
      if delay_left<0 then delay_left:=0;
      if (delay_left>0) then begin dec(delay_left); dec(time_left); end;
      if (time_left>=0) and (delay_left=0) then
        execute_instruction(n);
      if heat>=shutdown then begin cooling:=true; shields_up:=false; end;
      if heat>=500 then damage(n,1000,true);
     end;

   {--fix up variables--}
   thd:=(thd+1024) and 255;
   hd:=(hd+1024) and 255;
   shift:=(shift+1024) and 255;
   if tspd<-75 then tspd:=-75;
   if tspd>100 then tspd:=100;
   if spd<-75 then spd:=-75;
   if spd>100 then spd:=100;
   if heat<0 then heat:=0;
   if last_damage<maxint then inc(last_damage);
   if last_hit<maxint then inc(last_hit);

   {--update heat--}
   if shields_up and (game_cycle and 3=0) then inc(heat);
   if not shields_up then
    begin
     if heat>0 then
      case config.heatsinks of  (*heat adjustments*)
       5:if game_cycle and 1=0 then dec(heat);
       4:if game_cycle mod 3=0 then dec(heat);
       3:if game_cycle and 3=0 then dec(heat);
       2:if game_cycle and 7=0 then dec(heat);
       1:begin (*Do nothing, no adjustment needed*) end;
       else if game_cycle and 3=0 then inc(heat);
      end;
     if overburn and (game_cycle mod 3=0) then inc(heat);
     if (heat>0) then dec(heat);
     if (heat>0) and (game_cycle and 7=0) and (abs(tspd)<=25) then dec(heat);
     if (heat<=shutdown-50) or (heat<=0) then cooling:=false;
    end;
   if cooling then begin tspd:=0; end;
   heat_mult:=1;
   case heat of
    080..099:heat_mult:=0.98;
    100..149:heat_mult:=0.95;
    150..199:heat_mult:=0.85;
    200..249:heat_mult:=0.75;
    250..maxint:heat_mult:=0.50;
   end;
   if overburn then heat_mult:=heat_mult*1.30;
   if (heat>=475) and (game_cycle and 03=0) then damage(n,1,true) else
   if (heat>=450) and (game_cycle and 07=0) then damage(n,1,true) else
   if (heat>=400) and (game_cycle and 15=0) then damage(n,1,true) else
   if (heat>=350) and (game_cycle and 31=0) then damage(n,1,true) else
   if (heat>=300) and (game_cycle and 63=0) then damage(n,1,true);

   {--update robot in physical world--}
   {-acceleration-}
   if abs(spd-tspd)<=acceleration then spd:=tspd
      else begin
            if tspd>spd then inc(spd,acceleration)
                        else dec(spd,acceleration);
           end;
   {-turning-}
   tthd:=hd+shift;
   if (abs(hd-thd)<=turn_rate) or (abs(hd-thd)>=256-turn_rate) then
      hd:=thd
    else if hd<>thd then
     begin
      k:=0;
      if ((thd>hd) and (abs(hd-thd)<=128)) or
         ((thd<hd) and (abs(hd-thd)>=128)) then k:=1;
      if k=1 then hd:=(hd+turn_rate) and 255
             else hd:=(hd+256-turn_rate) and 255;
     end;
   hd:=hd and 255;
   if keepshift then shift:=(tthd-hd+1024) and 255;
   {-moving-}
   speed:=spd/100*(max_vel*heat_mult*speedadj);
   xv:= sint[hd]*speed;
   yv:=-cost[hd]*speed;
   if (hd=0) or (hd=128) then xv:=0;
   if (hd=64) or (hd=192) then yv:=0;
   if xv<>0 then ttx:=x+xv else ttx:=x;
   if yv<>0 then tty:=y+yv else tty:=y;
   if (ttx<0) or (tty<0) or (ttx>1000) or (tty>1000) then
      begin inc(ram[8]); tspd:=0; if abs(speed)>=max_vel/2 then damage(n,1,true); spd:=0; {ttx:=x; tty:=y;} end;
   for i:=0 to num_robots do
    if (i<>n) and (robot[i]^.armor>0) and (distance(ttx,tty,robot[i]^.x,robot[i]^.y)<crash_range)
       then begin
             tspd:=0; spd:=0; ttx:=x; tty:=y;
             robot[i]^.tspd:=0; robot[i]^.spd:=0;
             inc(ram[8]); inc(robot[i]^.ram[8]);
             if abs(speed)>=max_vel/2 then begin damage(n,1,true); damage(i,1,true); end;
            end;
   if ttx<0 then ttx:=0;
   if tty<0 then tty:=0;
   if ttx>1000 then ttx:=1000;
   if tty>1000 then tty:=1000;
   meters:=meters+distance(x,y,ttx,tty);
   if meters>=maxint then meters:=meters-maxint;
   ram[9]:=trunc(meters);
   x:=ttx; y:=tty;


   {--draw robot--}
   if armor<0 then armor:=0;
   if heat<0 then heat:=0;
   if graphix then
    begin
     if armor<>larmor then update_armor(n);
     if heat div 5<>lheat div 5 then update_heat(n);
     draw_robot(n);
    end;
   lheat:=heat; larmor:=armor;

   {--Cycle complete, inc counter--}
   inc(cycles_lived);
  end;
end;

procedure do_mine(n,m:integer);
var
 i,j,k,l:integer;
 d,r:real;
 source_alive:boolean;
begin
 with robot[n]^.mine[m] do
  if (x>=0) and (x<=1000) and (y>=0) and (y<=1000) and (yield>0) then
   begin
    for i:=0 to num_robots do
     if (robot[i]^.armor>0) and (i<>n) then
      begin
       d:=distance(x,y,robot[i]^.x,robot[i]^.y);
       if d<=detect then detonate:=true;
      end;
    if detonate then
     begin
      init_missile(x,y,0,0,0,n,mine_circle,false);
      kill_count:=0;
      if (robot[n]^.armor>0) then source_alive:=true else source_alive:=false;
      for i:=0 to num_robots do
       if {(i<>n) and} (robot[i]^.armor>0) then
        begin
         k:=round(distance(x,y,robot[i]^.x,robot[i]^.y));
         if k<yield then
          begin
           damage(i,round(abs(yield-k)),false);
           if (n in [0..num_robots]) and (i<>n) then
              inc(robot[n]^.damage_total,round(abs(yield-k)));
          end;
        end;
       if (kill_count>0) and (source_alive) and (robot[n]^.armor<=0) then dec(kill_count);
       if kill_count>0 then
        begin
         inc(robot[n]^.kills,kill_count);
         update_lives(n);
        end;
      if graphix then
       putpixel(round(x*screen_scale)+screen_x,round(y*screen_scale)+screen_y,0);
      yield:=0; x:=-1; y:=-1;
     end
    else
     begin
      (* Draw mine *)
      if graphix and (game_cycle and 1=0) then
       begin
        main_viewport;
        setcolor(robot_color(n));
        line(round(x*screen_scale)+screen_x,round(y*screen_scale)+screen_y-1,
             round(x*screen_scale)+screen_x,round(y*screen_scale)+screen_y+1);
        line(round(x*screen_scale)+screen_x+1,round(y*screen_scale)+screen_y,
             round(x*screen_scale)+screen_x-1,round(y*screen_scale)+screen_y);
       end;
     end;
   end;
end;

procedure do_missile(n:integer);
var
 llx,lly,r,d,dir,xv,yv:real;
 i,j,k,l,xx,yy,tx,ty,dd,dam:integer;
 source_alive:boolean;
begin
 with missile[n] do
  if a=0 then exit else
  begin
   if a=1 then
    begin
     {--Look for collision w/ wall--}
     if (x<-20) or (x>1020) or (y<-20) or (y>1020) then a:=0;

     {--move missile--}
     llx:=lx; lly:=ly;
     lx:=x; ly:=y;
     if a>0 then
      begin
       hd:=(hd+256) and 255;
       xv:= sint[hd]*mspd;
       yv:=-cost[hd]*mspd;
       x:=x+xv;
       y:=y+yv;
      end;

     {--look for hit on a robot--}
     k:=-1; l:=maxint;
     for i:=0 to num_robots do
      if (robot[i]^.armor>0) and (i<>source) then
       begin
        d:=distance(lx,ly,robot[i]^.x,robot[i]^.y);
        {dir:=find_angle(lx,ly,robot[i]^.x,robot[i]^.y);
        j:=(round(dir/pi*128)+1024) and 255;}
        hd:=hd and 255;
        xx:=round( sint[hd]*d+lx);
        yy:=round(-cost[hd]*d+ly);
        r:=distance(xx,yy,robot[i]^.x,robot[i]^.y);
        if (d<=mspd) and (r<hit_range) and (round(d)<=l) then
         begin k:=i; l:=round(d); dd:=round(r); tx:=xx; ty:=yy; end;
       end;
     if k>=0 then  (*hit a robot!*)
      begin
       x:=tx; y:=ty; a:=2; rad:=0; lrad:=0;
       if source in [0..num_robots] then
        begin
         robot[source]^.last_hit:=0;
         inc(robot[source]^.hits);
        end;
       for i:=0 to num_robots do
        begin
         dd:=round(distance(x,y,robot[i]^.x,robot[i]^.y));
         if dd<=hit_range then
           begin
            dam:=round(abs(hit_range-dd)*mult);
            if dam<=0 then dam:=1;
            kill_count:=0;
            if (robot[source]^.armor>0) then source_alive:=true else source_alive:=false;
            damage(i,dam,false);
            if (source in [0..num_robots]) and (i<>source) then
              inc(robot[source]^.damage_total,dam);
            if (kill_count>0) and (source_alive) and (robot[source]^.armor<=0) then dec(kill_count);
            if kill_count>0 then
             begin
              inc(robot[source]^.kills,kill_count);
              update_lives(source);
             end;
           end;
        end;
      end;

     {--draw missile--}
     if graphix then
      begin
       main_viewport;
       setcolor(0);
       line(round(llx*screen_scale)+screen_x,round(lly*screen_scale)+screen_y,
            round(lx*screen_scale)+screen_x,round(ly*screen_scale)+screen_y);
       if a=1 then
        begin
         if mult>robot[source]^.shotstrength then setcolor(14+(game_cycle and 1)) else setcolor(15);
         line(round(x*screen_scale)+screen_x,round(y*screen_scale)+screen_y,
              round(lx*screen_scale)+screen_x,round(ly*screen_scale)+screen_y);
        end;
      end;
    end;
   if (a=2) then
    begin
     lrad:=rad;
     inc(rad);
     if rad>max_rad then a:=0;
     if graphix then
      begin
       main_viewport;
       setcolor(0);
       circle(round(x*screen_scale)+screen_x,round(y*screen_scale)+screen_y,lrad);
       if mult>1 then setcolor(14+(game_cycle and 1)) else setcolor(15);
       if max_rad>=blast_circle then setcolor(14);
       if max_rad>=mine_circle then setcolor(11);
       if a>0 then
        circle(round(x*screen_scale)+screen_x,round(y*screen_scale)+screen_y,rad);
      end;
    end;
  end;
end;

procedure show_statistics;
var
 i,j,k,n,sx,sy:integer;
begin
 if not windoze then exit;
 if graphix then
  begin
   sx:=24; sy:=93-num_robots*3;
   viewport(0,0,639,479);
   box(sx+000,sy,sx+591,sy+102+num_robots*12);
   hole(sx+004,sy+004,sx+587,sy+098+num_robots*12);
   setfillpattern(gray50,1);
   bar(sx+005,sy+005,sx+586,sy+097+num_robots*12);
   setcolor(15);
   outtextxy(sx+016,sy+020,'Robot            Scored   Wins  Matches  Armor  Kills  Deaths    Shots');
   outtextxy(sx+016,sy+030,'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~');
   n:=-1; k:=0;
   for i:=0 to num_robots do
    with robot[i]^ do
     if (armor>0) or (won) then begin inc(k); n:=i; end;
   for i:=0 to num_robots do
    with robot[i]^ do
     begin
      setcolor(robot_color(i));
      if (k=1) and (n=i) then j:=1 else j:=0;
      outtextxy(sx+016,sy+042+i*12,addfront(cstr(i+1),2)+' - '+addrear(fn,15)+cstr(j)
               +addfront(cstr(wins),8)+addfront(cstr(trials),8)
               +addfront(cstr(armor)+'%',9)+addfront(cstr(kills),7)
               +addfront(cstr(deaths),8)+addfront(cstr(match_shots),9));
     end;
   setcolor(15);
   outtextxy(sx+016,sy+064+num_robots*12,victor_string(k,n));
   if windoze then
    begin
     outtextxy(sx+016,sy+076+num_robots*12,'Press any key to continue...');
     flushkey; readkey;
    end;
  end
 else
  begin
   textcolor(15);
   write(#13+space(79)+#13);
   writeln('Match ',played,'/',matches,' results:');
   writeln;
   writeln('Robot            Scored   Wins  Matches  Armor  Kills  Deaths    Shots');
   writeln('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~');
   n:=-1; k:=0;
   for i:=0 to num_robots do
    with robot[i]^ do
     if (armor>0) or (won) then begin inc(k); n:=i; end;
   for i:=0 to num_robots do
    with robot[i]^ do
     begin
      textcolor(robot_color(i));
      if (k=1) and (n=i) then j:=1 else j:=0;
      writeln(addfront(cstr(i+1),2)+' - '+addrear(fn,15)+cstr(j)
             +addfront(cstr(wins),8)+addfront(cstr(trials),8)
             +addfront(cstr(armor)+'%',9)+addfront(cstr(kills),7)
             +addfront(cstr(deaths),8)+addfront(cstr(match_shots),9));
     end;
   textcolor(15);
   writeln;
   writeln(victor_string(k,n));
   writeln;
   {writeln('Press any key to continue...'); readkey;}
  end;
end;

procedure bout;
var
 i,j,k:integer;
 c:char;
 timer:longint;
 {FIFI}
 n:integer; {loop count for mem_watch}
 {/FIFI}
begin
 if quit then exit;

 inc(played);
 init_bout;
 bout_over:=false;

 {FIFI}
 if step_mode=0 then step_loop:=false else step_loop:=true; {set/clear loop flag}
 step_count:=-1; {will be set to 0 at first iteration of REPEAT ;) }
 if graphix and (step_mode>0) then for i:=0 to num_robots do draw_robot(i);
 {/FIFI}

 repeat
  inc(game_cycle);
  for i:=0 to num_robots do
   if robot[i]^.armor>0 then do_robot(i);
  for i:=0 to max_missiles do
   if missile[i].a>0 then do_missile(i);
  for i:=0 to num_robots do
   for k:=0 to max_mines do
    if robot[i]^.mine[k].yield>0 then do_mine(i,k);

  if graphix and timing then time_delay(game_delay);

  if keypressed then c:=upcase(readkey) else c:=#255;
  case c of
   {FIFI}
   'X': if not robot[0]^.is_locked then
         begin
          if not graphix then toggle_graphix;
          if robot[0]^.armor>0 then
           begin
            if temp_mode>0 then step_mode:=temp_mode else step_mode:=1;
            step_count:=-1;
            init_debug_window;
           end;
         end;
   {/FIFI}
   '+','=':if game_delay<100 then
            case game_delay of
              000..004:game_delay:=005;
              005..009:game_delay:=010;
              010..014:game_delay:=015;
              015..019:game_delay:=020;
              020..029:game_delay:=030;
              030..039:game_delay:=040;
              040..049:game_delay:=050;
              050..059:game_delay:=060;
              060..074:game_delay:=075;
              075..100:game_delay:=100;
            end;
   '-','_':if game_delay>0 then
            case game_delay of
              000..005:game_delay:=000;
              006..010:game_delay:=005;
              011..015:game_delay:=010;
              016..020:game_delay:=015;
              021..030:game_delay:=020;
              031..040:game_delay:=030;
              041..050:game_delay:=040;
              051..060:game_delay:=050;
              061..075:game_delay:=060;
              076..100:game_delay:=075;
            end;
   'G':toggle_graphix;
   else process_keypress(c);
  end; flushkey;
  if game_delay<0 then game_delay:=0;
  if game_delay>100 then game_delay:=100;
  case game_delay of
   000..001:k:=100;
   002..005:k:=50;
   006..010:k:=25;
   011..025:k:=20;
   026..040:k:=10;
   041..070:k:=5;
   071..maxint:k:=1;
   else k:=10;
  end;
  if not graphix then k:=100;
  if graphix then
   begin
    if ((game_cycle mod k)=0) or (game_cycle=10) then update_cycle_window;
   end else begin
    if (update_timer<>mem[0:$46C] shr 1) then update_cycle_window;
    update_timer:=mem[0:$46C] shr 1;
   end;
 until quit or gameover or bout_over;
 update_cycle_window;
 {if (not graphix) then writeln;}
 score_robots;
 show_statistics;
end;

procedure main;
var
 i,j,k,l,n,w:integer;
begin
 if graphix then begin_window;
 if matches>0 then
  for i:=1 to matches do
   bout;
 if not graphix then writeln;
 if quit then exit;
 if matches>1 then  {--Calculate overall statistics--}
  begin
   writeln; writeln;
   graph_mode(false);
   textcolor(15);
   writeln('Bout complete! (',matches,' matches)');
   writeln;
   k:=0; w:=0;
   for i:=0 to num_robots do
    with robot[i]^ do
     begin
      if wins=w then begin inc(k); end;
      if wins>w then begin k:=1; n:=i; w:=wins; end;
     end;
   writeln('Robot           Wins  Matches  Kills  Deaths    Shots');
   writeln('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~');
   for i:=0 to num_robots do
    with robot[i]^ do
     begin
      textcolor(robot_color(i));
      writeln(addfront(cstr(i+1),2)+' - '+addrear(fn,8)
             +addfront(cstr(wins),7)+addfront(cstr(trials),8)
             +addfront(cstr(kills),8)+addfront(cstr(deaths),8)
             +addfront(cstr(shots_fired),9));
     end;
   textcolor(15);
   writeln;
   if k=1 then writeln('Robot #',n+1,' (',robot[n]^.fn,') wins the bout! (score: ',w,'/',matches,')')
          else writeln('There is no clear victor!');
   writeln;
  end
 else if graphix then
  begin {matches=1 also}
   graph_mode(false);
   show_statistics;
  end;
 if report then write_report;
end;

begin
 init;
 main;
 shutdown;
end.
