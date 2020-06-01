package main

go func() {
    for i := 0; i < n; i++ {
      x1 := <-in1
      x2 := <-in2
      out <- f(x1) + f(x2)
    }
  }()
}
