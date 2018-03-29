package mutex

import (
	"sync"
)

var (
	mtx     sync.Mutex
	counter int
)

func Incrementor() {
	for i := 0; i < 1000; i++ {
		counter++
	}
}

func main() {
	go mtx.Incrementor()
}
