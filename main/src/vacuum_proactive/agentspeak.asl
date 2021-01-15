!start.

+!start <- configure; !!clean.

+!clean : clean <- !move; !!clean.
+!clean : dirty <- suck;  !!clean.
-!clean         <- !!clean.

+!move : pos_1 <- right.
+!move : pos_2 <- down.
+!move : pos_3 <- up.
+!move : pos_4 <- left.