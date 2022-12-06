(defparameter s '(("N" "V" "C" "S")
                  ("S" "N" "H" "J" "M" "Z")
                  ("D" "N" "J" "G" "T" "C" "M")
                  ("M" "R" "W" "J" "F" "D" "T")
                  ("H" "F" "P")
                  ("J" "H" "Z" "T" "C")
                  ("Z" "L" "S" "F" "Q" "R" "P" "D")
                  ("W" "P" "F" "D" "H" "L" "S" "C")
                  ("Z" "G" "N" "F" "P" "M" "S" "D")))

(defparameter s2 '(("N" "Z") ("D" "C" "M") ("P")))

(defun string-to-list (str)
  (if (not (streamp str))
      (string-to-list (make-string-input-stream str))
      (if (listen str)
          (cons (read str) (string-to-list str))
          nil)))

(defun get-instructions (filename)
  (with-open-file (stream filename)
    (loop for line = (read-line
                      stream nil)
          while line
          collect line)))

(defun run (filename)
  (LET ((INSTRUCTIONS (GET-INSTRUCTIONS FILENAME))
        (stacks s))
    (dolist (instruction instructions stacks)
      (let ((n-stacks (nth 1 (string-to-list instruction)))
            (from (1- (nth 3 (string-to-list instruction))))
            (to (1- (nth 5 (string-to-list instruction)))))
        (dotimes (i n-stacks)
          (push (pop (nth
                      from
                      stacks))
                (nth
                 to
                 stacks)))))))

(defun run1 (filename)
  (LET ((INSTRUCTIONS (GET-INSTRUCTIONS FILENAME))
        (stacks s))
    (dolist (instruction instructions stacks)
      (let ((n-stacks (nth 1 (string-to-list instruction)))
            (from (1- (nth 3 (string-to-list instruction))))
            (to (1- (nth 5 (string-to-list instruction)))))
        (setf (nth to stacks) (append (subseq (nth from stacks) 0 n-stacks) (nth to stacks)))
        (setf (nth from stacks) (subseq (nth from stacks) n-stacks))
        (print stacks)))))
      

