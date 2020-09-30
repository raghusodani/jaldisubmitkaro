using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoDestroy : MonoBehaviour {

    [Header("Snake Manager")]
    SnakeMovement SM;

    [Header("Hits to be destroyed")]
    public int life;
    public float lifeForColor;
    TextMesh thisTextMesh;

    GameObject[] ToDestroy;
    GameObject[] ToUnparent;

    [Header("Color Management")]
    int maxLifeForRed = 50;

    //To fix the initial position due to some issues
    Vector3 initialPos;
    public bool dontMove;

    //Initially set the size of the box
    void SetBoxSize()
    {
        float x;
        float y;

        //Debug.Log(Screen.height + "\n" + Screen.width + "\n" + Screen.height / Screen.width);

        transform.localScale *= ((float)Screen.width / (float)Screen.height) / (9f/16f) ;
    }

	// Use this for initialization
	void Start () {

        //Set the box size depending on the resolution
        SetBoxSize();

        //Set the Snake Movement
        SM = GameObject.FindGameObjectWithTag("SnakeManager").GetComponent<SnakeMovement>();

        //Initialize the amount of lives
        life = Random.Range(1, GameController.SCORE/2 + 5);

        if(transform.tag == "SimpleBox")
        {
            life = Random.Range(5, 50);
        }

        lifeForColor = life;

        //Initialize this text Mesh
        thisTextMesh = GetComponentInChildren<TextMesh>();
        thisTextMesh.text = "" + life;

        //Initialize the 2 arrays
        ToDestroy = new GameObject[transform.childCount];
        ToUnparent = new GameObject[transform.childCount];

        //Randomly spawn some bars
        StartCoroutine("EnableSomeBars");

        //Set the color of the box depending on the life
        SetBoxColor();

        //Values to fix the position of the block
        initialPos = transform.position;
        dontMove = false;
    }
	
	// Update is called once per frame
	void Update () {

        //Fix the position
        if(dontMove)
            transform.position = initialPos;

        if (SM.transform.childCount > 0 && transform.position.y - SM.transform.GetChild(0).position.y < -10)
            Destroy(this.gameObject);

        //SetBoxColor();

        lifeForColor = life;

        //If the block has 0 life
        if (life <= 0)
        {
            //Hide it
            transform.GetComponent<SpriteRenderer>().enabled = false;

            //Hide the text
            transform.GetComponentInChildren<MeshRenderer>().enabled = false;

            //Disable the box Collider
            transform.GetComponent<BoxCollider2D>().enabled = false;



            //Play the particle System if it's off
            if(transform.GetComponentInChildren<ParticleSystem>().isStopped)
                transform.GetComponentInChildren<ParticleSystem>().Play();

            //Destroy after 1 sec
            Destroy(this.gameObject, 0.7f);
        }

    }

    public void UpdateText()
    {
        thisTextMesh.text = "" + life;
    }

    IEnumerator EnableSomeBars()
    {
        int i = 0;

        //Add the GameObjects to the arrays
        while (i < transform.childCount)
        {
                if (transform.GetChild(i).tag == "Bar")
                {
                    int r = Random.Range(0, 6);

                    if (r == 1)
                    {
                        ToUnparent[i] = transform.GetChild(i).gameObject;
                    }
                    else
                        ToDestroy[i] = transform.GetChild(i).gameObject;

                    i++;
                    yield return new WaitForSeconds(0.01f);
                }
                else
                    i++;
        }


        //Delete and unparent
        for (int k = 0; k < ToUnparent.Length; k++)
        {
            if(ToUnparent[k] != null)
                ToUnparent[k].transform.parent = null;

            if(ToDestroy[k] != null)
                Destroy(ToDestroy[k]);
        }

        yield return null;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.transform.tag == "SimpleBox" && transform.tag == "Box")
        {
            Destroy(collision.transform.gameObject);
        } else if(transform.tag == "SimpleBox" && collision.transform.tag == "SimpleBox")
        {

            Destroy(collision.transform.gameObject);
        }
    }

    private void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.transform.tag == "SimpleBox" && transform.tag == "Box")
        {
            Destroy(collision.transform.gameObject);
        }
        else if (transform.tag == "SimpleBox" && collision.transform.tag == "SimpleBox")
        {
            Destroy(collision.transform.gameObject);
        }


    }

    private void OnCollisionStay2D(Collision2D collision)
    {
        if (collision.transform.tag == "SimpleBox" && transform.tag == "Box")
        {
            Destroy(collision.transform.gameObject);
        }

        else if(collision.transform.tag == "SimpleBox" && transform.tag == "SimpleBoc")
        {
            Debug.Log("Overlapping");
        }

    }

    public void SetBoxColor()
    {
        Color32 thisImageColor = GetComponent<SpriteRenderer>().color;

        if (lifeForColor > maxLifeForRed)
            thisImageColor = new Color32(255, 0, 0, 255);

        else if (lifeForColor >= maxLifeForRed / 2 && lifeForColor <= maxLifeForRed)
            thisImageColor = new Color32(255, (byte)(510 * (1 - (lifeForColor / maxLifeForRed))), 0, 255);

        else if (lifeForColor > 0 && lifeForColor < maxLifeForRed)
            thisImageColor = new Color32((byte)(510 * lifeForColor / maxLifeForRed), 255, 0, 255);

        GetComponent<SpriteRenderer>().color = thisImageColor;

    }
}
