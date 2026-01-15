# My analogy of How I see floating point

I carried out an two separate experiment with the physical things I had around me.


---

## Experiment 1

I had an empty water bottle (container), this container was my **scale**.

In floating point terms, that’s the **exponent**. It decides how big the world is that I’m measuring in.



When I filled the bottle with water, that water was my **mantissa** — the meaningful substance that actually carries the value. 

I dropped a single bead into the bottle, the bead was also part of the mantissa, but whether it would change anything depends on the size of my container.



The bottle I used is very large, so the bead doesn’t raise the water level at all.

This was not because the bead wasn’t real, but because at that scale there is no way to represent such a tiny change. The resolution is too coarse.

The bead falls between measurable levels and disappears.



### My Conclusion was :

The exponent doesn’t change what the mantissa _is_ — it changes how finely the mantissa can be measured. 

The mantissa is always made of the same fixed amount of “water,” but the exponent stretches or compresses the ruler used to read it.

---

## Experiment 2 

The same thing happens with my experiment of a pen and a pen case.

The pen case sets the scale.

I put a grain of dust inside, the dust doesn’t affect the value of what I have, not because it has zero mass, but because at that scale there is no representable difference between “pen” and “pen plus dust.”

---

## How this experiment helped my understanding of how floating point works
So, In Floating point : the larger the container (exponent), the larger the smallest noticeable change.

That means the smallest noticeable change increased when the bottle got bigger.

So, Small details don’t become small — they become **unrepresentable**.