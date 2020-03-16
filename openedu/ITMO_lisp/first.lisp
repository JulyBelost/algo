(setf x (read))
(dotimes (i (ceiling (integer-length x) 8))
    (setf x (dpb
             (change-byte (ldb (byte 8 (* i 8)) x))
             (byte 8 (* i 8)) x)))
(print x)
