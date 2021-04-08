SET GBDK=..\..\..\gbdk\bin\

%GBDK%lcc -c -o gbt_player.o gbt_player.s
%GBDK%lcc -c -o gbt_player_bank1.o gbt_player_bank1.s 
%GBDK%sdar q gbt_player.lib gbt_player.o gbt_player_bank1.o 
del /Q *.o