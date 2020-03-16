;;;; read 3x dimentional array from input and print number of occurences
;;;; for most common string

(defparameter arr (read))
(defvar dim (array-dimensions arr))
(defvar occ '())
(defvar par '())
(defvar lan nil)
(dotimes(i (car dim))
    (dotimes(j (cadr dim))
        (dotimes(k (caddr dim))
            (setf lan (aref arr i j k))
            (setf par (assoc lan occ :test #'string=))
            (if par
            (push (cons lan (+ 1 (cdr par))) occ) (push (cons lan 1) occ))
                )))
(defvar res 0)
(dolist (l occ) (if (> (cdr l) res) (setf res (cdr l))))
(print res)
