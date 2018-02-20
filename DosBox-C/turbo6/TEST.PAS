uses dos, crt, filelib, graph;

procedure txy(x,y:integer; s:string);
begin
     setfillstyle(1,0);
     bar(x,y,x+length(s)*8,y+7);
     outtextxy(x,y,s);
end;

begin
     txy(1,1,"test");
end;