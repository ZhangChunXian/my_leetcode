class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = []

    def next(self, val: int) -> float:
        size, queue = self.size, self.queue
        queue.append(val)

        windows_sum = sum(queue[-size:])

        return windows_sum / min(len(queue), size)