+button_start <- +pos_1.

// plans for dirty location
+pos_1 : dirty & button_start <- suck; right.
+pos_2 : dirty <- suck; down.
+pos_3 : dirty <- suck; up.
+pos_4 : dirty <- suck; left.

// plans for clean location
+pos_1 : clean & button_start <- right.
+pos_2 : clean <- down.
+pos_3 : clean <- up.
+pos_4 : clean <- left.

+full_deposit <- empty.