(define fibonacci
  (lambda (n)
    (cond
      ((<= n 2) 1)
      (else (+ (fibonacci (- n 1)) (fibonacci (- n 2))))
    )
  )
)

(define fib-helper
  (lambda (a b n)
    (cond
      ((= n 0) b)
      (else (fib-helper b (+ a b) (- n 1)))
    )
  )
)

(define fib
  (lambda (n)
    (cond
      ((<= n 2) 1)
      (else (fib-helper 1 1 (- n 2)))
    )
  )
)

(define log10
  (lambda (x)
    (/ (log x) (log 10))))

(define fib-helper-gt
  (lambda (a b nth num)
    (cond
      ((>= b num) (cons nth b))
      (else (fib-helper-gt b (+ a b) (+ nth 1) num))
    )
  )
)

(define fib_gte_n
  (lambda (n)
    (cond
      ((<= n 1) 1)
      (else (fib-helper-gt 1 1 2 n))
    )
  )
)

