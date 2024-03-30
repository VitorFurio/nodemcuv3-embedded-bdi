!init.

+!init <- !!clean; !!connect.

+!clean : clean <- !move; !!clean.
+!clean : dirty <- suck;  !!clean.
-!clean         <- !!clean.

+!connect : true <- connect_to_wifi.

+!move : pos_1 <- right.
+!move : pos_2 <- down.
+!move : pos_3 <- up.
+!move : pos_4 <- left.
